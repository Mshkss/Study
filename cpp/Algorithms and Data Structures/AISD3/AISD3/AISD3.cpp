#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

int linearSearch(const vector<int>& arr, int key) {
    auto begin = std::chrono::steady_clock::now();
    int n = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            cout << "Число " << key << " найдено в массиве линейным поиском под индексом " << i << endl;
            n++;
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    if (n == 0) cout << "Число " << key << " не найдено в массиве линейным поиском" << endl;

    std::cout << "The time: " << elapsed_ms.count() << " nsec\n";

    return 1;
}

int interpolationSearch(const vector<int>& arr, int key) {
    auto begin1 = std::chrono::steady_clock::now();
    int n = 0;
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) {
            cout << "Число " << key << " найдено в массиве интерполяционным поиском под индексом " << pos << endl;
            n++;
        }

        if (arr[pos] < key) {
            low = pos + 1; // Искомое значение в верхней половине
        }
        else {
            high = pos - 1; // Искомое значение в нижней половине
        }
    }

    auto end1 = std::chrono::steady_clock::now();
    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
 
    if (n == 0) cout << "Число " << key << " не найдено в массиве интерполяционным поиском" << endl;

    std::cout << "The time: " << elapsed_ms1.count() << " nsec\n";

    return 2;
}


int main() {
    setlocale(0, "");

    ifstream inputFile("text.txt"); 
    if (!inputFile) {
        cerr << "Не удалось открыть файл" << endl;
        return 0;
    }

    int N;
    inputFile >> N; 

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        inputFile >> arr[i]; 
    }

    //std::sort(arr.begin(), arr.end());

    inputFile.close(); // числа готовы к сортировке

    int key;
    cout << "Введите число для поиска (0-1000): " << endl;
    cin >> key;

    int choose;
    cout << "Выберите сортировку (1/2), где 1 - Линейная, 2 - Интерполирующая: " << endl;
    cin >> choose;


    switch (choose)
    {
    case 1: {
        linearSearch(arr, key); // линейный поиск
        break;
    }
    case 2: {
         interpolationSearch(arr, key); // интерполирующий поиск
        break;
    }
    default: {
        cerr << "ошибка ввода!" << endl;
        system("pause");
        return 0;
        break;
    }
    }
    return 3;
}