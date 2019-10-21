#include<bits/stdc++.h>
using namespace std;
void balance_parentheses()
{
    stack<char> st;
    string str;
    cout << "Enter string may or may not containing parentheses:: ";
    cin >> str;
    int flag = 0; //flag is an arbitrary variable
    for (int i = 0; i < str.size();i++)
    //for length of the string calculated by number of letters
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            st.push(str[i]);       //push function to enter terms in a stack;
            flag = 1;
        }
        if (!st.empty())
        {
            if (str[i] == '}')
            {
                if (st.top() == '{')     // top of the stack;
                {
                    st.pop();    //pop function to delete terms from the top of array;
                    continue;
                }
                else
                    break;
            }
            if (str[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                    break;
            }
            if (str[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else
            break;
    }
    if ((st.empty()) && (flag == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cout << "Enter number of test cases:: ";
    cin >> t;
    for (int i = 0; i < t; i++)
        balance_parentheses();       //calling of function for checking of brackets;
    return 0;
}
