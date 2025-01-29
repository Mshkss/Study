
task = list(map(int, input().split()))

counter = 0

for i in range(1, len(task) - 1):
    if task[i] > task[i - 1] and task[i] > task[i + 1]:
        counter += 1

print(counter)