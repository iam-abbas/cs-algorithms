from dfa import *

auto, rules = read_file()
while(True):
    if auto!=[] or rules!=[]:  
        initial_input = input(
                '\n(!automaton = change automaton)\n(!exit = exit program)\nWords:> '
            )
        if (initial_input.lower()=='!exit'):
            break
        elif (initial_input.lower()=='!automaton'):
            auto, rules = read_file()
        else:
            process_word(initial_input, auto, rules)
    else:
        print("error in automaton information.\n")
        break