// C program to Print all combinations 
// of balanced parentheses 
# include<stdio.h> 
# define MAX_SIZE 100 

void _printParenthesis(int pos, int n, int open, int close); 

// Wrapper over _printParenthesis() 
void printParenthesis(int n) 
{ 
	if(n > 0) 
		_printParenthesis(0, n, 0, 0); 
	return; 
}	 

void _printParenthesis(int pos, int n, int open, int close) 
{ 
	static char str[MAX_SIZE];	 
	
	if(close == n) 
	{ 
		printf("%s \n", str); 
		return; 
	} 
	else
	{ 
		if(open > close) 
		{ 
			str[pos] = '}'; 
			_printParenthesis(pos+1, n, open, close+1); 
		} 
		
		if(open < n) 
		{ 
		str[pos] = '{'; 
		_printParenthesis(pos+1, n, open+1, close); 
		} 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	int n = 3; 
	printParenthesis(n); 
	getchar(); 
	return 0; 
} 
