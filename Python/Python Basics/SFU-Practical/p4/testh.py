from random import randint
mas = [randint(0, 100) for x in range(20)]

for i in range(len(mas)-1):
	for j in range(len(mas)-1-i):
		if mas[j] > mas[j+1]:
			mas[j], mas[j+1] = mas[j+1], mas[j]
print(mas)
to_find = mas[5]
low = 0
high = len(mas)
mid = int((low+high)/2)




print(low,mid,high)

