#include <bits/stdc++.h>

using namespace std;

const long double MINUS = 854321;
const long double PLUS = 754321;
const long double DIV = 654321;
const long double MULT = 554321;
const long double BRACK = 454321;
const long double IMPOSS = 354321;
const long double SIN = 1754321;
const long double COS = 1654321;
const long double SQRT = 1554321;
const long double TAN = 1454321;
const long double LOG = 1354321;
const long double POW = 6354321;
const long double CMP = 0.000001;
const long double PI = 3.141593;
//We can't make non-typed stack, but we should save our operands in the same stack? as numbers, so we need to have the constants, that will be meaning the operands


struct Stack{
    long double info; // Any type you need
    Stack *next;
};

void Push( Stack *&t, long double elem )//Add new element to the stack
{
    Stack *p = (Stack*) malloc(sizeof(Stack));
    (*p).info = elem;
    (*p).next = t;
    t = p;
}

bool CanPush( Stack *t, long double elem )//Checking a priority of new operand and the latest operand
{
    if ( elem == MINUS || elem == PLUS )
    {
        if ( t != NULL && (*t).info != BRACK )
        {
            return false;
        }
    }
    if ( elem == MULT || elem == DIV )
    {
        if ( t != NULL && !( (*t).info == PLUS || (*t).info == MINUS || (*t).info == BRACK ) )
        {
            return false;
        }
    }
    if ( elem == SQRT || elem == SIN || elem == COS || elem == TAN || elem == LOG )
    {
        if ( t != NULL && !( (*t).info == PLUS || (*t).info == MINUS || (*t).info == DIV || (*t).info == MULT || (*t).info == BRACK || (*t).info == POW ) )
        {
            return false;
        }
    }
    if ( elem == POW )
    {
        if ( t != NULL && !( (*t).info == PLUS || (*t).info == MINUS || (*t).info == DIV || (*t).info == MULT || (*t).info == POW || (*t).info == BRACK ) )
        {
            return false;
        }
    }
    /*if ( elem == BRACK )
    {
        if ( t != NULL )
        {
            return false;
        }
    }*/
    return true;
}

long double Pop( Stack *&t )// Get the first element from the stack and delete it
{
    if ( t == NULL )
    {
        return IMPOSS;
    }
    long double el = (*t).info;
    t = (*t).next;
    return el;
}

long double MakeDouble( string s )//Returning a double from a string
{
    long double a = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        a = a * 10 + s[i] - '0';
    }
    return a;
}

string Reform( string s )//Making a given example easier to work
{
    string s1 = "";
    for ( int i = 0; i < s.size(); i++ )
    {
        if ( '0' <= s[i] && '9' >= s[i] )
        {
            s1 += s[i];
        }
        else if ( s[i] <= 'z' && s[i] >= 'a' )
        {
            if ( s[i+1] == 'q' )
            {
                s1 += 'Q';
                i += 3;
            }
            else if ( s[i] == 's' )
            {
                s1 += 'S';
                i += 2;
            }
            else if ( s[i] == 'c' )
            {
                s1 += 'C';
                i += 2;
            }
            else if ( s[i] == 'l' )
            {
                s1 += 'L';
                i += 1;
            }
            else
            {
                s1 += 'T';
                i += 1;
            }
        }
        else
        {
            if (  ( i == 0 && ( s[i] == '-' ) ) || ( s[i] == '-'  && s[i-1] != ')'  && ( s[i-1] < '0' || s[i-1] > '9') ) )
            {
                s1 += '0';
            }
            s1 += s[i];
        }
    }
    return s1;
}

void PrintStack( Stack *t )// Print the Stack from the last, to the first elements
{
    long double a = Pop( t );
    while ( a != IMPOSS )
    {
        if ( abs( a - MINUS ) <= CMP )
        {
            cout << '-';
        }
        else if ( abs( a - DIV ) <= CMP )
        {
            cout << '/';
        }
        else if ( abs( a - MULT ) <= CMP )
        {
            cout << '*';
        }
        else if ( abs( a - PLUS ) <= CMP )
        {
            cout << '+';
        }
        else if ( abs( a - LOG ) <= CMP)
        {
            cout << "log";
        }
        else if ( abs( a - SQRT ) <= CMP)
        {
            cout << "sqrt";
        }
        else if ( abs( a - TAN ) <= CMP)
        {
            cout << "tan";
        }
        else if ( abs( a - COS ) <= CMP)
        {
            cout << "cos";
        }
        else if ( abs( a - SIN ) <= CMP)
        {
            cout << "sin";
        }
        else if ( abs( a - POW ) <= CMP)
        {
            cout << "^";
        }
        else
        {
            cout << a;
        }
        a = Pop( t );
        cout << ' ';
    }
    cout << '\n';
}

bool IsOperand( char ch )
{
    return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^';
}

bool IsNum( char ch )
{
    return ch >= '0' && ch <= '9';
}

bool IsCorrect( string s )// Checking if the example is wrong
{
    Stack *top = NULL;
    char ch = s[0];
    for ( int i = 1; i <= s.size(); ch = s[i++] )
    {
        if ( ch == '(' )
        {
            Push( top, '(' );
        }
        if ( ch == ')' )
        {
            long double a = Pop( top );
            if ( a == IMPOSS )
            {
                return false;
            }
        }
        if ( ( IsOperand( ch ) && i == s.size() ) ||  ( IsOperand( ch ) && IsOperand( s[i] ) ) )
        {
            return false;
        }
    }
    long double a = Pop( top );
    if ( a != IMPOSS )
    {
        return false;
    }
    return true;
}

void ReverseStack( Stack *&t )
{
    Stack *t1 = NULL;
    while ( t != NULL )
    {
        Push( t1, Pop( t ) );
    }
    t = t1;
}

Stack *top2 = NULL;
Stack *top1 = NULL;

int main()
{
    string example;
    cin >> example;
    example = Reform( example );
    char ch = example[0];
    string s = "";
    if ( !IsCorrect( example) )//If the example is wrong, we won't work with it
    {
        cout << "Error.";
        return 0;
    }
    for ( int i = 0; i < example.size(); ch = example[++i] )
    {
        if ( ch <= '9' && ch >= '0' )//Getting integer from the example
        {
            s += ch;
        }
        else
        {
            if ( s[0] <= '9' && s[0] >= '0' )//Pushing the latest integer to the PRN
            {
                Push( top2, MakeDouble( s ) );
            }
            if ( ch != ')' )//Pushing the latest operand to the operand's stack
            {
                if ( ch == '-' )
                {
                    while ( !CanPush( top1, MINUS ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, MINUS );
                }
                if ( ch == '*' )
                {
                    while ( !CanPush( top1, MULT ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, MULT );
                }
                if ( ch == '/' )
                {
                    while ( !CanPush( top1, DIV ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, DIV );
                }
                if ( ch == '+' )
                {
                    while ( !CanPush( top1, PLUS ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, PLUS );
                }
                if ( ch == '(' )
                {
                    while ( !CanPush( top1, BRACK ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, BRACK );
                }
                if ( ch == '^' )
                {
                    while ( !CanPush( top1, POW ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, POW );
                }
                if ( ch == 'Q' )
                {
                    while ( !CanPush( top1, SQRT ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, SQRT );
                }
                if ( ch == 'T' )
                {
                    while ( !CanPush( top1, TAN ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, TAN );
                }
                if ( ch == 'S' )
                {
                    while ( !CanPush( top1, SIN ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, SIN );
                }
                if ( ch == 'L' )
                {
                    while ( !CanPush( top1, LOG ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, LOG );
                }
                if ( ch == 'C' )
                {
                    while ( !CanPush( top1, COS ) )
                    {
                        Push( top2, Pop( top1 ) );
                    }
                    Push( top1, COS );
                }
            }
            else//moving all operands from brackets to the PRN
            {
                double a = 0;
                while ( a != BRACK )//
                {
                    a = Pop( top1 );
                    Push( top2, a );
                }
                Pop( top2 );
            }
            s = "";
        }
    }
    if ( example[example.size() - 1] <= '9' && example[example.size() - 1] >= '0' )//If last number isn't in the PRN, we move it there
    {
        Push( top2, MakeDouble( s ) );
    }
    while ( top1 != NULL )//Moving all latest operands, that we didn't pull in PRN to it
    {
        Push( top2, Pop( top1 ) );
    }
    ReverseStack( top2 );//reversing PRN, to work with it in the right order
    while ( top2 != NULL )//Counting PRN
    {
        long double a = Pop( top2 );
        if ( abs( a - MINUS ) <= CMP )
        {
            long double a = Pop( top1 ), b = Pop( top1 );
            if ( a == IMPOSS || b == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, b - a );
        }
        else if ( abs( a - DIV ) <= CMP )
        {
            long double a = Pop( top1 ), b = Pop( top1 );
            if ( a == 0 || a == IMPOSS || b == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, b / a ) ;
        }
        else if ( abs( a - MULT ) <= CMP )
        {
            long double a = Pop( top1 ), b = Pop( top1 );
            if ( a == IMPOSS || b == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, b * a );
        }
        else if ( abs( a - PLUS ) <= CMP )
        {
            long double a = Pop( top1 ), b = Pop( top1 );
            if ( a == IMPOSS || b == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, b + a );
        }
        else if ( abs( a - SQRT ) <= CMP )
        {
            long double a = Pop( top1 );
            if ( a == IMPOSS || a < 0 )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, pow( a, 0.5 ) );
        }
        else if ( abs( a - POW ) <= CMP )
        {
            long double a = Pop( top1 ), b = Pop( top1 );
            if ( a == IMPOSS || b == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, pow( b, a ) );
        }
        else if ( abs( a - TAN ) <= CMP )
        {
            long double a = Pop( top1 );
            if ( a == IMPOSS || abs( cos( a ) ) <= CMP )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, tan( a ) );
        }
        else if ( abs( a - COS ) <= CMP )
        {
            long double a = Pop( top1 );
            if ( a == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, cos( a ) );
        }
        else if ( abs( a - SIN ) <= CMP )
        {
            long double a = Pop( top1 );
            if ( a == IMPOSS )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, sin( a ) );
        }
        else if ( abs( a - LOG ) <= CMP )
        {
            long double a = Pop( top1 );
            if ( a == IMPOSS || a <= 0 )//Checking if we there are not enough numbers for this operand, so the example is incorrect
            {
                cout << "Error.";
                return 0;
            }
            Push( top1, log( a ) );
        }
        else
        {
            Push( top1, a );
        }
    }
    if ( top1 == NULL )//If there are no numbers in example, the example is incorrect
    {
        cout << "Error.";
        return 0;
    }
    cout << setprecision(6) << fixed << Pop( top1 );//Printing the answer for the example
    return 0;
}// You can add other operands, if it necessary
