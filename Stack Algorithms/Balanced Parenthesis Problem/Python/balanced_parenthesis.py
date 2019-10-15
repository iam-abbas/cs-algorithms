def balanced(string): 
    opening_parens = [ '(', '[', '{' ]
    closing_parens = [ ')', ']', '}' ]
    parens_dict = dict(zip(opening_parens, closing_parens))
    
    stack = []
    for char in string:
        if char in opening_parens:
            stack.append(char)
        elif char in closing_parens:
            if not stack or char != parens_dict[stack.pop()]:
                return False
    return not stack

if __name__ == '__main__':
    balanced_expression = '{[()()[]{}((()))]}'
    print balanced(balanced_expression)
    imbalanced_expression = '{[()()[]{}((()))]}}'
    print balanced(imbalanced_expression)
    invalid_expression = '{[()()[]{}((()))]}}{'
    print balanced(invalid_expression)
