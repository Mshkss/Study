from rect import Rectangle
import pickle

rect1=Rectangle('rect1', 1,1)
rect2=Rectangle('rect2', 2,2)
rect3=Rectangle('rect3', 3,3)

spisok=[rect1,rect2,rect3]
with open(r'D:\Python Projects\OPP\p8\1\rect.txt', 'w') as file:
    for rect in spisok:
        data = f"{rect.name};{rect.getwidth()};{rect.getheight()}\n"
        file.write(data)
        print(data)


###task3

rect4=Rectangle('rect4', 4,4)
rect5=Rectangle('rect5', 5,5)
spisok.append(rect4)
spisok.append(rect5)

with open(r'D:\Python Projects\OPP\p8\1\rect.txt', 'a') as file:
    for rect in [rect4, rect5]:
        data = f"{rect.name};{rect.getwidth()};{rect.getheight()}\n"
        file.write(data)
        print(data)
        

# Чтение данных из файла с помощью метода readline()
with open(r'D:\Python Projects\OPP\p8\1\rect.txt', 'r') as file:
    while True:
        line = file.readline()
        if not line:  # Если достигнут конец файла
            break
        print(line.strip())  # Выводим строку без лишних пробелов

# Чтение данных из файла с помощью метода readline()
with open(r'D:\Python Projects\OPP\p8\1\rect.txt', 'r') as file:
    while True:
        line = file.readline()
        if not line:  # Если достигнут конец файла
            break
        print(line.strip())  # Выводим строку без лишних пробелов

# Чтение данных из файла с помощью метода readlines()
with open(r'D:\Python Projects\OPP\p8\1\rect.txt', 'r') as file:
    lines = file.readlines()  # Читаем все строки в список
    for line in lines:
        print(line.strip())  # Выводим каждую строку без лишних пробелов

import pickle

# Сохранение списка объектов в бинарный файл
with open(r'D:\Python Projects\OPP\p8\1\rects.pkl', 'wb') as file:
    pickle.dump(spisok, file)

# Чтение данных из бинарного файла
with open(r'D:\Python Projects\OPP\p8\1\rects.pkl', 'rb') as file:
    loaded_spisok = pickle.load(file)

# Проверим загруженные объекты
for rect in loaded_spisok:
    print(f"{rect.name}; {rect.getwidth()}; {rect.getheight()}")

# Сохранение каждого объекта в отдельный файл
for i, rect in enumerate(loaded_spisok):
    with open(fr'D:\Python Projects\OPP\p8\1\rect_{i}.pkl', 'wb') as file:
        pickle.dump(rect, file)

# Чтение данных из файлов, если мы не знаем количество объектов
loaded_rects = []
i = 0

while True:
    try:
        with open(fr'D:\Python Projects\OPP\p8\1\rect_{i}.pkl', 'rb') as file:
            loaded_rect = pickle.load(file)
            loaded_rects.append(loaded_rect)
            i += 1
    except FileNotFoundError:
        break

# Проверим загруженные объекты
for rect in loaded_rects:
    print(f"{rect.name}; {rect.getwidth()}; {rect.getheight()}")

import shelve

# Сохранение данных в бинарный файл-хранилище
with shelve.open(r'D:\Python Projects\OPP\p8\1\rects_shelve') as shelf:
    for rect in loaded_spisok:
        shelf[rect.name] = rect

# Получение данных
with shelve.open(r'D:\Python Projects\OPP\p8\1\\rects_shelve') as shelf:
    for key in shelf:
        rect = shelf[key]
        print(f"{rect.name}; {rect.getwidth()}; {rect.getheight()}")

# Обновление данных (например, изменим ширину первого прямоугольника)
with shelve.open(r'D:\Python Projects\OPP\p8\1\rects_shelve') as shelf:
    rect_to_update = shelf['rect1']
    rect_to_update.width = 10  # Изменяем ширину
    shelf['rect1'] = rect_to_update  # Сохраняем изменения

# Удаление данных (например, удалим прямоугольник с именем 'rect2')
with shelve.open(r'D:\Python Projects\OPP\p8\1\rects_shelve') as shelf:
    del shelf['rect2']






# # Создаем экземпляр класса Rectangle
# rect = Rectangle(12, 12)
# # Выводим параметры прямоугольника
# print(rect)  
# # Вычисляем площадь
# print("Area:", rect.area())  # Area: 50
# # Вычисляем периметр
# print("Perimeter:", rect.perimeter())  # Perimeter: 30
# # Диагональ
# print("Diagonal:", rect.digonal())
# # Квадрат ли
# print(rect.isSquare())
# rect.ask_to_change_dimensions()
# print(rect)