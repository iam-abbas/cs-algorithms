Convex Hull --> Monotone chain algorithm

Given a set of points, the task is to find the covex hull of the given points. The convex hull is the smallest convex polygon that contains all the points.


Examples:

Input: Points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}}
Output:
(0, 0)
(3, 0)
(3, 3)
(0, 3) 



Approach--> Monotone chain algorithm constructs the convex hull in O(n * log(n)) time. We have to sort the points first and then calculate the upper and lower hulls in O(n) time. The points will be sorted with respect to x-coordinates (with respect to y-coordinates in case of a tie in x-coordinates), we will then find the left most point and then try to rotate in clockwise direction and find the next point and then repeat the step until we reach the rightmost point and then again rotate in the the clockwise direction and find the lower hull.


