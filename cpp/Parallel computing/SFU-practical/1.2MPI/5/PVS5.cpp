#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Задаем размер массива прямо в коде
    int N = 10; // Размер массива (например, 100 элементов)

    if (N <= 0) {
        if (rank == 0) {
            std::cerr << "Array size must be positive." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    std::vector<int> array;
    int chunk_size = N / size;
    int remainder = N % size;

    // Массив для каждого процесса
    std::vector<int> local_chunk;

    if (rank == 0) {
        // Генерация массива в мастер-процессе
        std::srand(std::time(0));
        array.resize(N);
        for (int i = 0; i < N; ++i) {
            array[i] = std::rand() % 100; // Числа от 0 до 99
        }

        std::cout << "Generated array: ";
        for (int i = 0; i < N; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    // Определяем количество элементов для текущего процесса
    int local_size = (rank < remainder) ? chunk_size + 1 : chunk_size;
    local_chunk.resize(local_size);

    // Распределение массива между процессами
    if (rank == 0) {
        int offset = 0;
        for (int i = 1; i < size; ++i) {
            int send_size = (i < remainder) ? chunk_size + 1 : chunk_size;
            MPI_Send(&array[offset], send_size, MPI_INT, i, 0, MPI_COMM_WORLD);
            offset += send_size;
        }
        // Мастер-процесс берет свою часть
        local_chunk.assign(array.begin(), array.begin() + local_size);
    }
    else {
        MPI_Recv(local_chunk.data(), local_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Вычисление частичной суммы
    int local_sum = 0;
    for (int val : local_chunk) {
        local_sum += val;
    }

    std::cout << "Process " << rank << " local sum: " << local_sum << std::endl;

    // Сбор частичных сумм в мастер-процессе
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        std::cout << "Total sum: " << total_sum << std::endl;
    }

    MPI_Finalize();
    return 0;
}