n = int(input())

task = [2**i for i in range(n,0,-1)]
print(" ".join(map(str, task)))