#include <iostream> 
using namespace std; 
int multrecur(int n, int m) 
{ 
    if (n > 0 && m < 0) { 
        return multrecur(m, n); 
    } 
    else if (n < 0 && m < 0) { 
        return multrecur((-1 * n), (-1 * m)); 
    } 
    if (n > m) { 
        return multrecur(m, n); 
    } 
    else if (m != 0) { 
        return n + multrecur(n, m - 1); 
    } 
    else { 
        return 0; 
    } 
} 
int main() 
{ 
    cout << "10 * 5 = " << multrecur(10, 5) << endl; 
    cout << "10 * (-5) = " << multrecur(10, -5) << endl; 
    cout << "(-10) * 5 = " << multrecur(-10, 5) << endl; 
    cout << "(-10) * (-5) = " << multrecur(-10, -5) << endl; 
    return 0; 
} 