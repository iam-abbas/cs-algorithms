#include <iostream> 
#include <time.h> 
#define e 2.71828 
using namespace std; 
 
int roundNo(float num) 
{ 
    return num < 0 ? num - 0.5 : num + 0.5; 
} 
void printBestCandidate(int candidate[], int n) 
{
    int sample_size = roundNo(n/e); 
    cout << "\n\nSample size is " << sample_size << endl; 
    int best = 0;  
    for (int i = 1; i < sample_size; i++) 
        if (candidate[i] > candidate[best]) 
            best = i;  
    for (int i = sample_size; i < n; i++) 
        if (candidate[i] >= candidate[best]) { 
            best = i; 
            break; 
        } 
  
    if (best >= sample_size) 
        cout << endl << "Best candidate found is "
            << best + 1 << " with talent " 
            << candidate[best] << endl; 
    else
        cout << "Couldn't find a best candidate\n"; 
} 
  
int main() 
{ 
int n = 8;  
int candidate[n]; 
srand(time(0));     
    for (int i = 0; i < n; i++) 
     candidate[i] = 1 + rand() % 8; 
     cout << "Candidate : "; 
     for (int i = 0; i < n; i++) 
       cout << i + 1 << " "; 
       cout << endl; 
       cout << "  Talents : "; 
       for (int i = 0; i < n; i++) 
        cout << candidate[i] << " "; 
      printBestCandidate(candidate, n); 
  return 0; 
} 