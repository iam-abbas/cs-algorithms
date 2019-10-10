// Problem statement :
// Given n balloons, indexed from 0 to n-1.
// Each balloon is painted with a number on it represented by array nums.
// You are asked to burst all the balloons.
// If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
// Here left and right are adjacent indices of i.
// After the burst, the left and right then becomes adjacent.
#include <vector>
#include <assert.h>

int burst_baloons(const std::vector<int> baloons) {
    int *nums = new int[baloons.size() + 2];
    int n = 1;
    for (int x : baloons)
        if (x > 0)
            nums[n++] = x;
    nums[0] = nums[n++] = 1;

    int **dp = new int*[n];
    for(int i = 0; i < n; ++i)
        dp[i] = new int[n];
    for (int k = 2; k < n; ++k)
        for (int left = 0; left < n - k; ++left) {
            int right = left + k;
            for (int i = left + 1; i < right; ++i) {
                int challenger = nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right];
                dp[left][right] = std::max(dp[left][right], challenger);
            }
        }

    return dp[0][n - 1];
}

int main() {
    const std::vector<int> input {3, 1, 5, 8};
    int result = burst_baloons(input);
    assert(result == 167);
    return 0;
}
