/*Problem Statement:
    Given 2 strings say str1 and str2 and 3 operations are allowed
        a) Insertion
        b) Deletion
        c) Replacement .
    So our job is find the minimum number of edits(operation) to make both the strings equal.

    Example:
    Input:
        str1="geek" 
        str2="geesk"

    Output:
        1
    Explanation:
        Deletion of character 's' from str2 will make both the strings same.
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1("geek"),str2("geesk");

    int l1=str1.length();
    int l2=str2.length();


    //str1 as column
    //str2 as row
    int matrix[l2+1][l1+1];

    for(int row=0;row<=l2;row++)
    {
        for(int col=0;col<=l1;col++)
        {
            //to make null to string
                if(row==0)
                matrix[row][col]=col;

                else if(col==0)
                matrix[row][col]=row;

            //if the characters match then skip
            //match then keep as diagonal
            else if(str1[col-1]==str2[row-1])
                matrix[row][col]=matrix[row-1][col-1];

            else
            //not match 1+min(left,top,diagonal)
                matrix[row][col]=1+min(matrix[row-1][col],min(matrix[row][col-1],matrix[row-1][col-1]));
            }
    }
cout<<matrix[l2][l1];

    return 0;
}
