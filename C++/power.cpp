#include <iostream>

using namespace std;

double power(double x, int y)
{
    double n,m;
    if(y==0) { // base
        return 1;
    }
    if(y < 0){  // negative
        n = (1 / x) * power(x, (y + 1)/2);
        return n*n;
    }
    if(y % 2 == 0) {
        m = power(x, y/2);
        return m*m;
    } else {
        return x * power(x, y - 1);
    }
}

int main() 
{
	cout << "To calculate x^y ..." << endl;
	
	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;
	
	if(x == 0) {
		if (y > 0)
			cout << 0 << endl;
		else
			cout << "x^y is not defined" <<endl;
	}
	else {
		cout << power(x,y) << endl;
	}
	return 0;
}

