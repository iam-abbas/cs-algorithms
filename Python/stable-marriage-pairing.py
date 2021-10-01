import random  # Used in illustrative text case

# ---------------------------------------functions------------------------------------


class UnstableTableError(Exception):
    """ Error for unstable table when no stable pairings are possible. """


def make_proposals(preferences):
    """ Takes in a dictionary with key equal to a participant and
        value equal to a list of that participant's preferences.

        Function iterates over each participant in order to find and return
        a record of the proposals in the form of a dictionary.

        Each participant proposes in turn using its preference list and
        receives a proposal, accepting only the highest preferred
        proposal using its preference list and rejecting all others.

        Function returns when there are no longer any participants in the
        priority queue (participants left needing to propose) or there are
        no more participants to propose to.

        For example:

        Inputs of
            preferences = {
                'A': ['B', 'D', 'C'],
                'B': ['D', 'C', 'A'],
                'C': ['A', 'D', 'B'],
                'D': ['A', 'B', 'C'],
            }
        Outputs =>
            proposal_record = {
                'A': ['D', 'D'],
                'B': ['C', 'C'],
                'C': ['B', 'B'],
                'D': ['A', 'A'],
            }
    """
    proposal_record = {}
    proposers = []  # using non-optimal list here to represent priority queue

    # Create list of proposers and empty proposal_record for each
    for participant in preferences:
        proposers.append(participant)
        proposal_record[participant] = ["", ""]

    # breakpoint()
    # to show proposers and empty proposal_record

    while proposers:
        current_proposer = proposers.pop(0)

        # Get current proposer's preference list of proposees
        current_proposer_prefs = preferences[current_proposer][:]

        # Propose to each proposee in order until accepted
        for proposee in current_proposer_prefs:
            proposee_prefs = preferences[proposee]
            current_proposer_ranking = proposee_prefs.index(current_proposer)

            # get proposal_record for proposee and proposer
            proposee_proposal_to, proposee_proposal_from = proposal_record[proposee]
            proposer_proposal_to, proposer_proposal_from = proposal_record[current_proposer]

            # breakpoint()

            # if proposee has not accepted a proposal yet
            if not proposee_proposal_from:
                proposal_record[proposee][1] = current_proposer
                proposal_record[current_proposer][0] = proposee
                break

            # if current proposal is better than accepted proposal
            elif proposee_prefs.index(proposee_proposal_from) > current_proposer_ranking:
                proposal_record[proposee][1] = current_proposer
                proposal_record[current_proposer][0] = proposee

                # Reject previously accepted proposal symmetrically
                # Step 1: reset rejected participant's proposal record
                proposal_record[proposee_proposal_from][0] = ""
                # Step 2: put rejected participant at front of priority queue
                proposers.insert(0, proposee_proposal_from)
                # Step 3: remove rejected pairing symmetrically from the preference list
                preferences[proposee].remove(proposee_proposal_from)
                preferences[proposee_proposal_from].remove(proposee)
                break

            # Otherwise, proposee prefers previously accepted proposal
            else:
                # Update preference lists for rejected proposal
                preferences[proposee].remove(current_proposer)
                preferences[current_proposer].remove(proposee)

    return proposal_record


def is_stable_table(proposal_record):
    """ Function checks if a stable table exists.
        Takes in dictionary of lists and iterates over each list.
        Checks each list item is not equal to an empty string and
        each list pair is unique.
        Returns True, if not empty and is unique; otherwise returns False

        Examples Below:

        Stable table:
            Inputs of
                proposal_record =>
                {
                    'A': ['C', 'B'],
                    'B': ['A', 'D'],
                    'C': ['D', 'A'],
                    'D': ['B', 'C']
                }
            Outputs => True

        Unstable table:
            Inputs of
                proposal_record =>
                {
                    'A': ['D', 'D'],
                    'B': ['D', 'A'],
                    'C': ['', ''],
                    'D': ['A', 'A']
                }
            Outputs => False
    """
    proposers = set()
    proposees = set()
    for (proposee, proposer) in proposal_record.values():
        if not proposee or not proposer:
            return False
        if (proposer in proposers) or (proposee in proposees):
            return False

        proposers.add(proposer)
        proposees.add(proposee)

    return True


def remove_trailing_prefs(proposal_record, preferences):
    """ Function trims each preference list by eliminating possibilities indexed
        after accepted proposal
        Takes in two dictionaries: proposal_record and preference_lists
        Returns updated preference_lists

        For example:
        Inputs of
            proposal_record = {
                'A': ['C', 'B'], - proposed to C and accepted proposal from B
                'B': ['A', 'D'], - proposed to A and accepted proposal from D
                'C': ['D', 'A'], - proposed to D and accepted proposal from A
                'D': ['B', 'C'], - proposed to B and accepted proposal from C
            }
            preferences = {
                'A': ['C', 'B', 'D'], - remove all prefs that rank lower than B
                'B': ['A', 'C', 'D'],
                'C': ['D', 'B', 'A'],
                'D': ['B', 'A', 'C'], - remove 'A' since 'D' is removed from A's list
            }

        Outputs =>
            preferences = {
                'A': ['C', 'B'],
                'B': ['A', 'C', 'D'],
                'C': ['D', 'B', 'A'],
                'D': ['B', 'C'],
            }
    """
    for proposer in proposal_record:
        proposee = proposal_record[proposer][0]
        proposee_prefs = preferences[proposee]
        proposer_ranking = proposee_prefs.index(proposer)

        successors = proposee_prefs[proposer_ranking+1:]

        # Updated proposee's preferences, removing successors
        preferences[proposee] = proposee_prefs[:proposer_ranking+1]

        # Iterate over successors, deleting proposee from own preference list
        for successor in successors:
            if proposee in preferences[successor]:
                preferences[successor].remove(proposee)

    return preferences


def get_stable_match(preferences):
    """ Function takes in dictionary of each participant's preferences and
        finds stable pairings if it exists by iterating through
        participants while preference lists are greater than 1.
        Identifies cycles and removes cycle pairs to reduce participant's
        preference lists.

        Process is repeated until stable matches are found and preference
        lists are length of 1, returning stable pairings
        Or, returns UnstableTableError if stable matches are not possible.

        Identify cycles by
        - Creating two lists (p and q) until cycle is found in p
            p: [participant   ],[last item of q0],[last item of q1]...
            q: [2nd item of p0],[2nd item of p1 ],[2nd item of p2 ]...
        - Creates cycle list to then determine pairs and removes

        For example
        Input of
            preferences = {
                'A': ['C', 'B'],
                'B': ['A', 'C', 'D'],
                'C': ['D', 'B', 'A'],
                'D': ['B', 'C']
            }

        Identifies cycle:
            Starting with 'A'
                p = ['A', 'D', 'A']
                q = ['B', 'C',]
            Cycle found in p (p[0] == p[2])
            Cycle list = [('D', 'B'), ('A', 'C')]
            Pairs removed: ('B', 'C'), ('B', 'D') and ('C', 'A')
            Process repeats

        Output =>
            preferences = {'A': ['B'], 'B': ['A'], 'C': ['D'], 'D': ['C']}
    """

    for participant in preferences:
        p = [participant, ]
        q = []

        while len(preferences[participant]) > 1:
            def find_cycle():
                new_q = preferences[p[-1]][1]
                q.append(new_q)
                q_pref_list = preferences[new_q]
                new_p = q_pref_list[-1]

                if new_p in p:
                    p.append(new_p)
                    return

                p.append(new_p)
                find_cycle()

            find_cycle()

            # start at beginning of found cycle, create list representing cycle path
            start = p.index(p[-1])
            cycle = [(p[i + 1], q[i]) for i in range(start, len(p) - 1)]
            # breakpoint()

            # from cycle path, find pairs to remove
            elimination_pairs = find_pairs_to_remove(cycle, preferences)

            try:
                preferences = remove_pairs(elimination_pairs, preferences)
            except UnstableTableError:
                return UnstableTableError

            # reset p and q for next iteration
            p = [participant, ]
            q = []

    return preferences


def find_pairs_to_remove(cycle, preferences):
    """ Find all cycle pairs to remove from each participant's preference lists.
        Takes in a list of tuples representing a cycle path found and
        dictionary containing each participant's preferences.
        Returns list of tuples representing pairs to remove.

        For example:
        Input of
            cycle = [('D', 'B'), ('A', 'C')]
            preferences = {
                'A': ['C', 'B'],
                'B': ['A', 'C', 'D'],
                'C': ['D', 'B', 'A'],
                'D': ['B', 'C']
            }

        where participant = 'B'
            participant_prefs = ['A', 'C', 'D']
            first_pref = 'A'
            successors = ['C', 'D']

        Output =>
            pairs = [('B', 'C'), ('B', 'D'), ('C', 'A')]
    """
    pairs = []
    for i, (_, participant) in enumerate(cycle):
        # grab the preference list for participant
        participant_prefs = preferences[participant]
        # first_pref is a pointer for where to start successors list
        first_pref = cycle[(i - 1) % len(cycle)][0]
        # successors is the tail of the cycle which needs to be removed
        successors = participant_prefs[participant_prefs.index(
            first_pref) + 1:]
        # breakpoint()

        for successor in successors:
            pair = (participant, successor)
            if pair not in pairs and pair[::-1] not in pairs:
                pairs.append((participant, successor))
    return pairs


def remove_pairs(pairs, preferences):
    """ Takes in list of tuples representing pairs to remove
        and dictionary of each participant's preferences.
        Returns updated preferences.

        For example:
        Input of
            pairs = [('B', 'C'), ('B', 'D'), ('C', 'A')]
            preferences = {
                'A': ['C', 'B'],
                'B': ['A', 'C', 'D'],
                'C': ['D', 'B', 'A'],
                'D': ['B', 'C']
            }

        Output =>
            preferences = {
                'A': ['B'],
                'B': ['A'],
                'C': ['D'],
                'D': ['C']
            }
    """

    for (left, right) in pairs:
        preferences[left].remove(right)
        preferences[right].remove(left)
        if not preferences[left] or not preferences[right]:
            raise UnstableTableError

    return preferences


def find_stable_pairings(preferences):
    """ Takes in a dictionary with key equal to a participant and
        value equal to a list of preferences

        Returns stable pairing for each participant

        For example:
        Input of
        preferences = {
            "A": ["C", "B", "D"],
            "B": ["A", "C", "D"],
            "C": ["D", "B", "A"],
            "D": ["B", "A", "C"],
        }
        Output =>
        preferences_list = {
            'A': ['B'],
            'B': ['A'],
            'C': ['D'],
            'D': ['C']
        }
    """
    proposal_record = make_proposals(preferences)

    if not is_stable_table(proposal_record):
        return UnstableTableError("No stable pairings possible")

    updated_preferences = remove_trailing_prefs(
        proposal_record,
        preferences
    )

    try:
        print("matching roomates are ")
        return get_stable_match(updated_preferences)
    except UnstableTableError:
        return UnstableTableError("No stable pairings possible")


# -------------------------- main code --------------------------


# looping it 30 times so we can get alteast one no stable matching pairings

for k in range(30):
    rithm = {}
    N = 6   # we can change here N no of roommates (N is only even)
    for i in range(1, N+1):
        temp = []
        while len(temp) != N-1:
            num = random.randint(1, N)
            if num not in temp and num != i:
                temp.append(num)
        rithm[i] = temp

    i = 0
    j = 0
    for i in range(1, N+1):
        print(f"{i} --", end=" ")
        for j in range(len(rithm[i])):
            print(f"{rithm[i][j]}", end=" ")
        print(" ")

    print(find_stable_pairings(rithm))
    print("\n")
