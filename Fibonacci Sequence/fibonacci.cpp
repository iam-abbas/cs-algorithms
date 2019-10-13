#include <iostream>

using namespace std;

int main() {
    int term1 = 0 , term2 = 1, i, number, sequence;

    cout << "What is the number of terms: ";
    cin >> number;
    cout << "Fibonacci sequence: ";

    for(i=1; i<=number; i++) {
        sequence = (term1 + term2);
        cout << term1 << " ";
        term1 = term2;
        term2 = sequence;
    }
}
