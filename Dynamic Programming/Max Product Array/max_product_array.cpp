/*
* @Author: pedrotorres
* @Date:   2019-06-11 22:10:26
* @Last Modified by:   pedrotorres
* @Last Modified time: 2019-10-08 11:09:01
*/

// complexity: O(n)
// description: find maximum product in an array

#include <bits/stdc++.h>

#define EPS 0.0000000001

using namespace std;

int main(){
	float array[] = {0.2, 0.9, 0.02, 0.5, 0.1, 0.4, 0.5, 0.5, 0.5, 0.7, 0.00001, 0.8, 0.5};
	int n = sizeof(array) / sizeof(array[0]);
	float maxsf, maxeh;
	int start, end, s;
	
	maxsf = 0, maxeh = 1;
	start = 0, end = 0; s = 0;

	for (int k = 0; k < n; k++){
		maxeh = maxeh * array[k];

		if (maxsf < maxeh){
			maxsf = maxeh;
			start = s;
			end = k;
		}

		if (maxeh < 1.0){
			maxeh = 1.0;
			s = k + 1;
		}
	}

	printf("%d %d %.2f\n" ,start, end, maxsf);

	return 0;
}