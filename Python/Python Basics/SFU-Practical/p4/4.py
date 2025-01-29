#4 задача по варианту - 3v
N = int(input())

task = list(map(int, input().split()))




for i in range(0, len(task)-1,2):
		temp = task[i] 
		task[i] = task[i+1]
		task[i+1] = temp


print(" ".join(map(str, task)))