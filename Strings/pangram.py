from string import ascii_lowercase


def is_pangram(sentence):
    return not set(ascii_lowercase) - set(sentence.lower())

