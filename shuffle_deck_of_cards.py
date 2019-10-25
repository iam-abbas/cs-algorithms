# Shuffle a deck of cards
from random import randint

suits = ['Clubs', 'Diamonds', 'Hearts', 'Spades']
values = ['Ace', 'King', 'Queen', 'Jack', 'Ten', 'Nine', 'Eight', 'Seven', \
          'Six', 'Five', 'Four', 'Three', 'Two']

def main():
    
    # Create deck
    deck = []
    for suit in suits:
        for value in values:
            deck.append("{} of {}".format(value, suit))

    # shuffle
    deckSize = len(deck)
    maxCardIdx = deckSize - 1
    for cardIdx in range(deckSize):
        randIdx = randint(0, maxCardIdx)
        deck[cardIdx], deck[randIdx] = deck[randIdx], deck[cardIdx]

    for idx, card in enumerate(deck, 1):
        print("{}. {}".format(idx, card))


if __name__ == "__main__":
    main()
