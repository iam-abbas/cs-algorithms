#include<iostream>
#include<regex>

using namespace std;

int main()
{
	//the string that will be matched with the regex
	string s;
	cin >> s;
	
	if(regex_match(s, regex("(str)(.*)"))
		cout << "the entered string contains 'str'";
	else
		cout << "there was no match between the entered string and 'str'";

	return 0;
}
