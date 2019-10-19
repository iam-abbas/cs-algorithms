#include <list>
#include <string>
#include <assert.h>

/**
   * Predicate test if string contains balanced brackets
   * @param string to be tested
   * @return bool
*/
bool stringBracketIsBalancedCheck(const std::string& input_string) {

	char left_bracket, right_bracket; 
	std::list<char> bracket_list;
	
	//parse the string for parentheses
	for (char ch : input_string)
	{
		if (ch == '(' || ch == ')') bracket_list.push_back(ch);
	}
	
	//both stacks must equal each other
	if (bracket_list.size() % 2 != 0) return false;
	
	while (bracket_list.size())
	{
		//pull the first element - must be a left bracket
		left_bracket = bracket_list.front();
		if (left_bracket != '(') return false;
		
		//find the first right bracket
		auto itr = std::find(bracket_list.cbegin(), bracket_list.cend(), ')');
		
		if (itr != bracket_list.cend())
		{	
			bracket_list.erase(itr);
			bracket_list.pop_front();
		}
		else
			return false;
	}
	return true;
}

// Driver  code 
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