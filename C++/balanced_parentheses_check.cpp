#include <stack>
#include <string>
#include <assert.h>

/**
   * Predicate test if string contains balanced brackets
   * @param string to be tested
   * @return bool
*/
bool stringBracketIsBalancedCheck(const std::string& input_string) {

	char left_bracket, right_bracket;
	std::stack<char> bracket_stack;

	//parse the string for parentheses (right to left)
	for (int i = input_string.length(); i >= 0; --i)
	{
		char ch = input_string[i];
		if (ch == '(' || ch == ')') bracket_stack.push(ch);
	}

	//stack must have an even number of elements
	if (bracket_stack.size() % 2 != 0) return false;

	while (bracket_stack.size())
	{
		//pull the first element - must be a left bracket
		left_bracket = bracket_stack.top();
		if (left_bracket != '(') return false;
	
		//remove the left bracket from the stack
		bracket_stack.pop();

		std::stack<char> temp_stack;
		
		//find the first right bracket
		while (bracket_stack.size())
		{
			char top_value = bracket_stack.top();
			if (top_value == ')')
			{
				//remove the right bracket from the original stack
				bracket_stack.pop();
				//push all the temp_stack values back onto the original stack maintaining the order
				while (temp_stack.size()) 
				{
					bracket_stack.push(temp_stack.top());
					temp_stack.pop();
				}
				break;
			}
			else
			{
				//if not a right bracket, push onto the temporary stack and pop from original
				temp_stack.push(bracket_stack.top());
				bracket_stack.pop();
				//if all the chars in the original stack are not the right bracket = unbalanced
				if (bracket_stack.size() == 0)
					return false;
			}
		}
	}
	return true;
}


// Driver  code with unit tests
int main()
{
	//test with no strings
	assert(stringBracketIsBalancedCheck("") == true);

	//test with one bracket
	assert(stringBracketIsBalancedCheck("(") == false);
	assert(stringBracketIsBalancedCheck(")") == false);


	//test with two brackets
	assert(stringBracketIsBalancedCheck("()") == true);
	assert(stringBracketIsBalancedCheck("((") == false);
	assert(stringBracketIsBalancedCheck(")(") == false);

	//test with two nested brackets
	assert(stringBracketIsBalancedCheck("(())") == true);
	assert(stringBracketIsBalancedCheck("()()") == true);
	
	//tests with n brackets
	assert(stringBracketIsBalancedCheck("(())") == true);
	assert(stringBracketIsBalancedCheck("(()()()()())") == true);
	assert(stringBracketIsBalancedCheck("(()()()()()") == false);
	assert(stringBracketIsBalancedCheck("((((((()))))))") == true);
	assert(stringBracketIsBalancedCheck("((((((())))))") == false);
	assert(stringBracketIsBalancedCheck("((((((()))))()") == false);
	
	return 0;
}