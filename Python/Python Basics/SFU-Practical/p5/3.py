# task = "C:\WINDOWS\MEDIA\work.wav"
task = input()
result = ""
# print(task)
for i in range(len(task)):
	if task[i] != "\\":
		result +=task[i]
	else:
		print(result)
		result = ""
print(result)