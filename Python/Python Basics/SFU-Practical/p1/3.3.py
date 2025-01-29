#Напишите программу, которая вводит натуральное число N и выводит первые N чётных натуральных чисел.

last_digit = int(input())

result = ""

n = 0
i = 0
while i < last_digit: 
	i+=1
	n+=2
	result += str(n) + " "

print(result)