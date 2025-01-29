task = list(map(int, input().split()))

# Извлекаем элементы с четными индексами
even_indexed_elements = [task[i] for i in range(len(task)) if i % 2 == 0]

# Выводим элементы через пробел
print(" ".join(map(str, even_indexed_elements)))
