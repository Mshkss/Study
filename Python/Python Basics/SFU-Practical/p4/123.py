task = [1,2,3,4,5,6]
for i in range(len(task)//2):
	temp = task[len(task)-i]
	task[i] = task[len(task)-i]
	task[len(task)-i] = temp


print(task)
