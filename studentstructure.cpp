#include <iostream>
using namespace std;

struct student
{
    char name[50];
    int roll;
    float marks1;
    float marks2;
    float marks3;
} s[5];

int main()
{
	int x;
    cout << "Enter information of students: " << endl;

    // storing information
    for(int i = 0; i < 5; ++i)
    {
        
        cout << "For roll number" <<endl;
        cin>>s[i].roll ;

        cout << "Enter name: ";
        cin >> s[i].name;

        cout << "Enter marks1: ";
        cin >> s[i].marks1;
        cout << "Enter marks2: ";
        cin >> s[i].marks2;
        cout << "Enter marks3: ";
        cin >> s[i].marks3;

        cout << endl;
    }

    cout << "Displaying Information: " << endl;

    // Displaying information
    for(int i = 0; i < 5; ++i)
    {
    	x=(s[i].marks1+s[i].marks2+s[i].marks3);
        cout << "\nRoll number: " << s[i].roll << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Marks1: " << s[i].marks1 << endl;
        cout << "Marks2: " << s[i].marks2 << endl;
        cout << "Marks3: " << s[i].marks3 << endl;
        cout <<"total marks:"<<x<<endl;
        cout<<"percentage:"<<x/3<<endl;
    }

    return 0;
}

