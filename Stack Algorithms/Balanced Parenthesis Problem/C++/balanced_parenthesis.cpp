#include<bits/stdc++.h>
using namespace std;

bool balanced(string str){
	stack<char> s;
	for(int i=0; i<str.length(); i++){
		if(str[i] == '{' || str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		else if(!s.empty() && (str[i] == '}' && s.top() == '{')|| (str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '['))
			s.pop();
		else
			return false;
	}
	
	return s.empty();	
}
int main(){
	//An application on how stack can be useful to check standard Balanced bracket problem
	string str;
	char choice;
	do{
		cin>>str;
		(balanced(str))?cout<<"Balanced":cout<<"Not Balanced";
		cout<<"\nDo you want to try again?(y/n) ";
		cin>>choice;
	}while(choice != 'n');
	return 0;
}
