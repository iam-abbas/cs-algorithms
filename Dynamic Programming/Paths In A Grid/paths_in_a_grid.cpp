#include <iostream>
using namespace std;

// Problem statement : 
// To find a path from the upper-left corner to the lower-right
// corner of an n × n grid, such that we only move down and right. Each square
// contains a positive integer, and the path should be constructed so that the sum of
// the values along the path is as large as possible.

// Recurrence relation : sum(y, x) = max( sum(y, x-1),
//                                        sum(y-1, x)) + value[y][x];


int main() {
  
  // Grid Dimension
  int n = 5;
  
  // sample input
  int grid[n+1][n+1] = {
    {0, 0, 0, 0, 0, 0},
    {0, 3, 7, 9, 2, 7},
    {0, 9, 8, 3, 5, 5},
    {0, 1, 7, 9, 8, 5},
    {0, 3, 8, 6, 4, 10},
    {0, 6, 3, 9, 7, 8}
  };
    
  // dp table
  int sum[n+1][n+1];
  
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      sum[i][j] = 0;

  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      sum[y][x] = max(sum[y][x-1], sum[y-1][x]) + grid[y][x];
    }
  }

  int ans = sum[n][n];
  
  cout << ans << endl;

  return 0;
}
