
# pickle: Подходит для простого хранения объектов Python, не предназначен для работы с большими объемами данных или сложными структурами. Не поддерживает параллельный доступ.

import pickle

# Данные для хранения
car_data = {
    'brand': 'Toyota',
    'color': 'Red'
}

# Сохранение данных в файл
with open('car_data.pkl', 'wb') as file:
    pickle.dump(car_data, file)

# Чтение данных из файла
with open('car_data.pkl', 'rb') as file:
    loaded_data = pickle.load(file)
    
print("pickle:", loaded_data)

# shelve: Удобен для хранения объектов в формате ключ-значение. Также не подходит для больших объемов данных и не поддерживает сложные запросы.

import shelve
# Открытие файла для хранения данных
with shelve.open('car_shelve') as db:
    db['car1'] = {'brand': 'Toyota', 'color': 'Red'}
    db['car2'] = {'brand': 'Honda', 'color': 'Blue'}

# Чтение данных
with shelve.open('car_shelve') as db:
    car1 = db['car1']
    print("shelve:", car1)