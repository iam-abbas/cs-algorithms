// Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

#include <math.h>
#include <assert.h>

int consecutiveNumbersSum(int N) {
    int res = 0;
    double NN = N;
    int maxTerms = (int)(sqrt(8 * NN + 1) - 1) / 2;
    for (int n = 1; n <= maxTerms; n++) {
        int temp = N - (n - 1) * n / 2;
        if (temp > 0 && temp % n == 0) res++;
    }
    return res;
}

int main() {
    int sum = consecutiveNumbersSum(15);
    assert(sum == 4);
    return 0;
}
