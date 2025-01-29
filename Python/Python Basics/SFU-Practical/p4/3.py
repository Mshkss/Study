def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return False

# Чтение входных данных
N, K = map(int, input().split())
first_array = list(map(int, input().split()))
second_array = list(map(int, input().split()))

# Для каждого элемента второго массива выполняем бинарный поиск в первом массиве
for number in second_array:
    if binary_search(first_array, number):
        print("YES")
    else:
        print("NO")
