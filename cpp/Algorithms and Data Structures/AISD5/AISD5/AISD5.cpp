#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <thread>

// Функция проверки сортировки массива
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Реализация Bogosort
void bogosort(std::vector<int>& arr) {
    auto begin = std::chrono::steady_clock::now();
    std::random_device rd;
    std::mt19937 g(rd());

    while (!isSorted(arr)) {
        std::shuffle(arr.begin(), arr.end(), g);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Время сортировки Bogosort " << elapsed_ms.count() << " nsec\n";
}

// Сортировка Шелла
void shellSort(std::vector<int>& arr) {
    auto begin = std::chrono::steady_clock::now();
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Время сортировки Шелла " << elapsed_ms.count() << " nsec\n";
}

int main() {

    setlocale(0, "");
    std::vector<int> arr = { 5, 2, 9, 1, 5, 6 };


    std::cout << "До сортировки: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    bogosort(arr);

    std::cout << "После соритровки Bogosort: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = { 5, 2, 9, 1, 5, 6 };



    shellSort(arr2);

    std::cout << "После сортировки Шелла: ";
    for (const auto& num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}