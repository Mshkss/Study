from cmath import inf
from random import randint

# Ввод данных
A, B, N = map(int, input().split())

# Генерация массива
#task = [10, 10, 19, 12, 13, 17, 13, 11, 14, 14]
task = [randint(A, B) for _ in range(N)]
print(" ".join(map(str, task)))

c=float(-inf)
tempnum = float(-inf)

for i in range(N//2):
	if (task[i] + task[N-i-1]) >= c and (task[i] + task[N-i-1])%2==0:
		tempnum = i+1
		if((task[i] + task[N-i-1]) == c) and (i > tempnum): 
			c = task[i] + task[N-i-1]
			tempnum = i+1
		else: 
			c = task[i] + task[N-i-1]

		
if c == (-inf):print("0 0")
else: print(tempnum, N-tempnum+1)

#if(task[i] + task[N-i-1]) == c: 