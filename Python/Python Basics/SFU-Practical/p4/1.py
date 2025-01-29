from random import randint

N = int(input())


task = [randint(20, 100) for x in range(10)]
print(task)
for i in range(N):
	task.remove(max(task))
	task.remove(min(task))
print(task)

