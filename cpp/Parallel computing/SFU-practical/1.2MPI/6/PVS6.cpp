#include <mpi.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Создаем массив с помощью генерации
void generateArray(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
    }
}

// Печатаем массив
void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message << ": ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int arraySize = 16; // Размер массива
    std::vector<int> array;

    if (rank == 0) {
        // Создаем мастер-процесс
        array.resize(arraySize);
        generateArray(array, arraySize);
        printArray(array, "Initial array");
    }

    // Указываем азмер подмассива для каждого процесса
    int subArraySize = arraySize / size;

    // Проверка корректности числа процессов
    if (arraySize % size != 0) {
        if (rank == 0) {
            std::cerr << "Array size must be divisible by the number of processes" << std::endl;
        }
        MPI_Finalize();
        return -1;
    }

    // Создаем буфер для подмассива
    std::vector<int> subArray(subArraySize);

    // Разделяем массив на подмассивы
    MPI_Scatter(array.data(), subArraySize, MPI_INT, subArray.data(), subArraySize, MPI_INT, 0, MPI_COMM_WORLD);

    // Сортируем подмассив
    std::sort(subArray.begin(), subArray.end());

    // Выводим промежуточный результат
    std::cout << "Process " << rank << " sorted subarray: ";
    for (int val : subArray) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Собираем отсортированный подмассив
    std::vector<int> sortedArray;
    if (rank == 0) {
        sortedArray.resize(arraySize);
    }
    MPI_Gather(subArray.data(), subArraySize, MPI_INT, sortedArray.data(), subArraySize, MPI_INT, 0, MPI_COMM_WORLD);

    // Итоговая сортировка (если нужно объединение)
    if (rank == 0) {
        std::sort(sortedArray.begin(), sortedArray.end());
        printArray(sortedArray, "Final sorted array");
    }

    MPI_Finalize();
    return 0;
}
