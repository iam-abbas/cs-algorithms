total = int(input()) +1
quantity_coins = list(map(int, input().split()))
quantity_coins = [0] + quantity_coins
coins = [0,2,5,10,20,50,100]
value = [[0 for col in range(total)] for row in range(7)]
value[0][0] = 1

for i in range(1,len(coins)):
    for j in range(total):
        limit = min(quantity_coins[i],j//coins[i])
        for k in range(limit+1):
            value[i][j] = value[i][j] + value[i-1][j-(coins[i]*k)]
print(value[-1][-1])