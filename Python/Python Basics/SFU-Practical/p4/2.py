a = "Введите что то: "

task =[]
while a != "":
	a = input("Введите что то: ")
	if a not in task:
		task.append(a)

task.pop()
print(task)