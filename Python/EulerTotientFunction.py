def prime_factors(n):
    i = 2
    factors = [1]
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def is_prime(list):
    if len(list) == 2:
        return True
    else:
        return False


def prime_powers():
    list = [1, 2, 2, 3, 3]
    output_list = []
    for i in range(1, len(list) - 1):
        if list[i] == list[i + 1]:
            output_list.append(list[i] * list[i + 1])
    print(output_list)

def
n = int(input("Input Number?"))
factors_n = prime_factors(n)
print(factors_n)

if is_prime(factors_n):
    phi_n = n-1


print(phi_n)

#made some cool changes