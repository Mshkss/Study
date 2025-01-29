task = list(map(int, input().split()))

cc = 0
for c in task:
	if c > 0:
		cc+=1
print(cc)