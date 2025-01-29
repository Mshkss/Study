import numpy as np
import time

# list 
python_list = [i for i in range(1000000)]

# numpy
numpy_array = np.array(python_list)

def time_operation(func):
    start = time.time()
    func()
    end = time.time()
    return end - start

def list_operations():
    # Сложение всех элементов
    list_sum = sum(python_list)
    # Умножение каждого элемента на 2
    list_mult = [x * 2 for x in python_list]
    # Возведение каждого элемента в квадрат
    list_square = [x ** 2 for x in python_list]

def numpy_operations():
    # Сложение всех элементов
    numpy_sum = np.sum(numpy_array)
    # Умножение каждого элемента на 2
    numpy_mult = numpy_array * 2
    # Возведение каждого элемента в квадрат
    numpy_square = numpy_array ** 2

# list
list_time = time_operation(list_operations)
print(f"Время выполнения операций с Python списком: {list_time:.6f} секунд")

# numpy 
numpy_time = time_operation(numpy_operations)
print(f"Время выполнения операций с numpy массивом: {numpy_time:.6f} секунд")


