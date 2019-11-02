#include<iostream>
using namespace std;

void towerofHanoi(int n,char src,char dest,char helper)
{
    // Base case
    if(n==0)
    {
        return;
    }
    //Rec case
    // First step N-1 disks move from src to helper

    towerofHanoi(n-1,src,helper,dest);
    // Shift Nth disk from src to dest

    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest<<endl;

    // Move N-1 disk from helper to dest

    towerofHanoi(n-1,helper,dest,src);
}
int main()
{
    int n;
    cin>>n;
    towerofHanoi(n,'A','B','C');
    return 0;
}
