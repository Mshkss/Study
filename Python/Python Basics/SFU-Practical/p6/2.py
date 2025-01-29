# Читаем количество файлов
N = int(input().strip())

# Создаем словарь для хранения прав доступа к файлам
file_permissions = {}

# Считываем информацию о файлах и их операциях
for _ in range(N):
    line = input().strip().split()
    filename = line[0]
    permissions = set(line[1:])  # Храним операции в множестве для быстрого поиска
    file_permissions[filename] = permissions

# Читаем количество запросов
M = int(input().strip())

# Обрабатываем запросы
for _ in range(M):
    query = input().strip().split()
    operation = query[0].lower()  # Приводим к нижнему регистру
    filename = query[1]

    # Проверяем, разрешена ли операция для данного файла
    if filename in file_permissions and operation[0].upper() in file_permissions[filename]:
        print("OK")
    else:
        print("Access denied")
