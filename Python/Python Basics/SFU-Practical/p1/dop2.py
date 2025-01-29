def count_ways(n):
    money = [10, 5, 2, 1]
    ways = [0] * (n + 1)
    
    ways[0] = 1
    
    for coin in money:
        for amount in range(coin, n + 1):
            ways[amount] += ways[amount - coin]
    
    return ways[n]

n = int(input())

print(count_ways(n))