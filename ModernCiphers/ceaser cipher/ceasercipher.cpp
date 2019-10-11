

    #include<iostream>
    using namespace std;
    int main()
    {
        string str;
        int s,j,i=0;
        cin>>str>>s;
        while(str[i]!='\0')
        {
            if((str[i]>='0'&&str[i]<='9') || (str[i]>='a'&&str[i]<='z') || (str[i]>='A'&&str[i]<='Z'))
            {
                j=0;
                while(j<s)
                {
                    str[i]++;
                    j++;
                    if(str[i]==58) str[i]=48;
                    if(str[i]==91) str[i]=65;
                    if(str[i]==123) str[i]=97;
                    
                }
            }
            cout<<str[i];
            i++;
        
     
        }
    }

    /*
    SAMPLE INPUT

All-convoYs-9-be:Alert1.
4
*/

/*
SAMPLE OUTPUT

All-convoYs-9-be:Alert1.

*/


/*
 Explanation

First line contains the string to convert. S

Second line contains the number, encrypt key. K

A becomes E, Y becomes C, 9 becomes 3,

-, . unchanged.




*/