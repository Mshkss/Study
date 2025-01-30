#include <iostream>
#include <chrono>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <thread>
#include <list>

using namespace std;

int countDivisors(int n) { // нахождение кол-ва делителей
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

void sortSequence(list<int>& sequence) {
    auto begin1 = std::chrono::steady_clock::now();

    list<pair<int, int>> divisorsCount; // Список для хранения пар (число, количество делителей)
    for (int num : sequence) {
        divisorsCount.push_back({ num, countDivisors(num) });
    }

    // Сортировка списка по количеству делителей
    divisorsCount.sort([](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
        });
    auto end1 = std::chrono::steady_clock::now();

    cout << "Отсортированная с помощью list последовательность: " << endl;
    for (auto it = divisorsCount.rbegin(); it != divisorsCount.rend(); ++it) {
        cout << it->first << endl;
    }
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    std::cout << "The time: " << elapsed_ms.count() << " nsec\n";
}

int main()
{
    setlocale(0, "");
    const int size = 5;
    int mas_int[size] = { 1, 8, 12, 4, 8 };
    int mas_del[size]{};
    list<int> sequence = { 1, 8, 12, 4, 8 };
    sortSequence(sequence);

    auto begin = std::chrono::steady_clock::now();

    for (size_t i = 0; i < size; i++) // копирование из первого массива во второй 
    {
        mas_del[i] = mas_int[i];
    }

    int count = 0; // кол-во делителей
    for (size_t i = 0; i < size; i++) //нахождение кол-ва делителей
    {
        for (size_t j = 1; j <= mas_int[i]; j++)
        {
            if (mas_int[i] % j == 0) {
                count++;
            }
        }
        mas_del[i] = count;
        count = 0;
    }

    for (size_t i = 0; i < size; i++) // пузырьковая сортировка 
    {
        for (size_t j = 0; j < size; j++)
        {
            if (mas_del[j] < mas_del[j + 1]) {
                int buf_int = mas_int[j];
                int buf_del = mas_del[j];
                mas_int[j] = mas_int[j + 1];
                mas_del[j] = mas_del[j + 1];
                mas_int[j + 1] = buf_int;
                mas_del[j + 1] = buf_del;
            }
        }
    }
    auto end = std::chrono::steady_clock::now();

    cout << endl;
    cout << "Отсортированная с помощью массива последовательность: " << endl;
    for (int i = 0; i < size; i++) cout <<  mas_int[i] << endl;
    //cout << "masdel:" << endl;
    //for (int i = 0; i < size; i++) cout << "элемент массива " << i << " равен:" << mas_del[i] << endl;

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " nsec\n";
}