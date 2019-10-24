# fast_fib.py:
# ------------
#    This is an implementation of a faster way to get the n-th number in the
# Fibonacci Sequence. While the direct translation of the formula is O(2^n) and
# the classic dynamic programming approach is O(n), this algorithm, bases on
# fast exponentiation and Dijkstra's formula is O(log n).
#
# Dijsktra's formula for calculating the n-th Fibonacci number establishes the
# following recurrences:
#    Fib(0)         = 0
#    Fib(1)         = 1
#    Fib(2 * k)     = (2 * Fib(k-1) + Fib(k)) * Fib(k)
#    Fib(2 * k - 1) = Fib(k-1)^2 + Fib(k)^2

# Memorization object. We use a dictionary instead of a regular array/list,
# because most of the values will never be set (in fact, only a logarithmic
# number of them will be set).
memorized = {}

def fib(n):
    if memorized.get(n) is None:
        # This number has not been encountered yet
        if n < 2:
            # This is one of the base cases
            return n
        elif n % 2 == 0:
            # n is even and therefore is of the form n = 2 * k
            k = n / 2
            memorized[n] = (2 * fib(k-1) + fib(k)) * fib(k)  # memorize result
        else:
            # n is odd and therefore is of the form n = 2 * k - 1
            k = (n + 1) / 2
            memorized[n] =  fib(k-1)**2 + fib(k)**2  # memorize result
    return memorized[n]

# Main program, so we can test our immplementation
print 'Give me a non-negative integer >>' ,
n = int(input())
f = fib(n)
print 'The {}-th number in the fibonacci sequence is {}'.format(n, f)