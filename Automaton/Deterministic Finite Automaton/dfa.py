import re

# Receive a string in the following format
# ({alphabet}, {states}, transition function, initial state, {final states})
# and extract it to a list of attributes.
def get_automaton(raw_automaton):
    regex = r"{(.*?)}|(q.\d*\w*)"
    matches = re.finditer(regex, raw_automaton)
    automaton = [match.group(0).strip('{').rstrip('}').split(', ') for match in matches]
    print('automaton: ')
    for attribute in automaton:
        print(attribute)
    print('')
    return automaton

# Read the rules of production in a text and extract it to a list of production rules.
def get_production_rules(raw_rules):
    production_rules = [line.rstrip('\n').split(', ') for line in raw_rules]
    print('rules of production: ')
    for rule in production_rules:
        print(rule)
    print('')
    return production_rules

# Read and process a word, resulting in acception or rejection.
def process_word(word, automaton, production_rules):
    initial_state = automaton[2][0]
    actual_state = initial_state
    print('')
    for symbol in word:
        if symbol not in automaton[0]:  
            print("-> symbol '{0}' not found in alphabet.".format(symbol))
            print('\nword não aceita.')
            return False
        else:
            is_rule = False
        for rule in production_rules:
            if (actual_state==rule[0]) and (symbol==rule[1]):
                is_rule = True
                print(
                    "-> processing '{0}'. actual state {1}. final state {2}. ".format(
                            symbol, actual_state, rule[2]
                        )
                    )
                actual_state=rule[2]
                break
        if not is_rule:
            print("-> rule from actual state {0} to '{1}' not found.".format(
                        actual_state, symbol
                    )
                )
            print('\nword not accepted.')
            return False

    if (actual_state in automaton[3]):
        print('\nword accepted. ')
        return True
    else:
        print('\nword not accepted.')
        return False

# Open a file and return the automaton and it's production rules.
def read_file():
    while(True):
        my_file = input('name of file: ')
        if 'txt' not in my_file: 
            my_file += '.txt'
        try:
            fp = open(my_file, 'r')
            text = fp.readline()
            auto = automaton(text)
            text = fp.readlines()
            rules = production_rules(text)
            fp.close()
            return auto, rules
        except:
            print("error opening file.\n")
