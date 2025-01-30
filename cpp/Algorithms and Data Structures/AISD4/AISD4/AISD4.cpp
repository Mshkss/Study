#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

const int tableSize = 40;
int table[tableSize];

int hashFunction(int key) {
    return (key * key / 100) % tableSize;
}

void insert(int key) {
    int index = hashFunction(key);
    if (table[index] == -1) {
        table[index] = key;
    }
    else {
        int i = 1;
        int originalIndex = index;
        while (table[(index + i * i) % tableSize] != -1 && (index + i * i) % tableSize != originalIndex) {
            i++;
        }
        if (table[(index + i * i) % tableSize] == -1) {
            table[(index + i * i) % tableSize] = key;
        }
        else {
            cout << "таблица заполнена" << endl;
        }
    }
}

void display() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != -1) {
            cout << i << " : " << table[i] << endl;
        }
        else {
            cout << i << endl;
        }
    }
}

int search(int key) {

    int index = hashFunction(key);
    int i = 0;
    while (table[(index + i * i) % tableSize] != key && table[(index + i * i) % tableSize] != -1) {
        i++;
    }
    if (table[(index + i * i) % tableSize] == key) {
        return (index + i * i) % tableSize;
    }
    else {
        return -1;
    }
}

void remove(int key) {
    int index = search(key);
    if (index != -1) {
        table[index] = -1;
    }
    else cout << "нет такого значения";
}

int main() {
    setlocale(0, "");

    for (int i = 0; i < tableSize; i++) {
        table[i] = -1;
    }

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
    
    for (int i = 0; i < N; i++) {
        insert(arr[i]);
    }


    display();

    int key;
    cout << "Введите ключ:" << endl;
    cin >> key;

    int choose;
    cout << "выберите режим (1/2): Где 1 - вставить элемент в таблицу, 2 - удалить элемент из таблицы: " << endl;
    cin >> choose;

    switch (choose)
    {
    case 1: {
        insert(key);
        break;
    }
    case 2: {
        remove(key);
        break;
    }
    default:
        break;
    }

    display();
    return 0;
}