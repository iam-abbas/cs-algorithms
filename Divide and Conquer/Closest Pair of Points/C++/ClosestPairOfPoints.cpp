#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

//simple struct to represent points
struct point {
	float x, y;
};

bool compareX(point& p1, point& p2) {
	return p1.x < p2.x;
}

bool compareY(point& p1, point& p2) {
	return p1.y < p2.y;
}

//calculates distance between two points
float distance(point& p1, point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

//finds the closest points of a strip, used to check distances that cross 2 subparts of the problem
float midPointDist(vector<point>& strip, float min)  { 
    sort(strip.begin(), strip.end(), compareY);  
   
    for (int i = 0; i < strip.size(); i++)  
        for (int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < min; j++)  
            if (distance(strip[i],strip[j]) < min)  
                min = distance(strip[i], strip[j]);  
  
    return min;  
}  

/*main recursive algorithm that does the hard work
if the current size is 2 or less it returns the result
else divides the problem in 2 subproblems and calls itself on each
finishes using midPointDist to check the distance between points that cross the middle point
*/
float minDist(vector<point>& P, int ini, int fin) {
	if (fin - ini == 0)
		return FLT_MAX;
	else if (fin - ini == 1)
		return distance(P[ini], P[fin]);


	point mid = P[ini + (fin - ini) / 2];

	float min = minDist(P, ini, ini + (fin - ini) / 2);  
    float min2 = minDist(P, 1 + ini + (fin - ini) / 2, fin);

	if (min2 < min)
		min = min2;

	vector<point> strip;
	for (int i = ini; i < fin; i++)
		if (abs(P[i].x - mid.x) < min)
			strip.push_back(P[i]);


	return midPointDist(strip, min);
}

//sorts the vector using x coordinate and calls minDist
float closestPoints(vector<point>& P) {
	sort(P.begin(), P.end(), compareX);
	return minDist(P,0,P.size() - 1);
}

int main() {
	vector<point> P{ {1, 2}, {3, 8}, {10, 9}, {2, 5}, {7, 4}, {20, 11} };
	cout << "The minimum distance between two points is " << closestPoints(P);
	return 0;
}