#include <iostream> 
using namespace std; 
  
int countSetBit(int n) 
{ 
    int c = 0; 
    while (n) 
    { 
        c += n & 1; 
        n >>= 1; 
    } 
    return c; 
} 
  
int FlippedCount(int a, int b) 
{ 
    return countSetBit(a^b); 
} 
  

int main() 
{ 
    int n1 = 14; 
    int n2 = 50; 
    cout << FlippedCount(n1, n2)<<endl; 
    return 0; 
}
