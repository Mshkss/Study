/*
Пункт 1: вывод на консоль
Вариант 4: Элементы массива, значение которых по модулю больше 0,25.

Пункт 2.1: занесение в список
Вариант 3: Заносимая информация: элементы массива, значения которых по модулю больше значения предыдущего элемента.
Вид списка: односвязный кольцевой список.

Пункт 2.2: порядок сортировки списка
Вариант 1: По возрастанию.

Пункт 2.3: функция для элементов списка
Вариант 1: Минимум.

Пункт 3: построение гистограммы для элементов массива
Вариант 3: Гистограмма распределения разности текущего элемента массива и следующего (элемент с номером N не учитывать).
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

// Узел списка
struct Node {
    float value;
    Node* next;
    Node(float val) : value(val), next(nullptr) {}
};

// Кольцевой список
struct List {
    Node* head;

    List() : head(nullptr) {}

    // Вывод минимального значения
    float findMinimum() const {
        if (!head) throw runtime_error("Список пуст");
        float minVal = head->value;
        Node* current = head->next;
        while (current != head) {
            if (current->value < minVal) {
                minVal = current->value;
            }
            current = current->next;
        }
        return minVal;
    }

    // Вывод списка
    void printList() const {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->value << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    ~List() {
        if (!head) return;
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
};

int main() {
    setlocale(LC_ALL, "");

    int len, numBins, numThreads;
    cout << "Введите длину массива: ";
    cin >> len;
    cout << "Введите количество интервалов гистограммы: ";
    cin >> numBins;
    cout << "Введите количество потоков: ";
    cin >> numThreads;

    // Генерация массива
    vector<float> arr(len);

    for (auto& val : arr) {
        val = static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f;

    }

    omp_set_num_threads(numThreads);

    auto startTime = omp_get_wtime();

    // Пункт 1: Вывод элементов с |x| > 0.25
    cout << "\nЭлементы, модуль которых больше 0.25:\n";
#pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        if (fabs(arr[i]) > 0.25f) {
#pragma omp critical
            {
                cout << "Поток " << omp_get_thread_num() << ": Индекс " << i << ", Значение " << arr[i] << "\n";
            }
        }
    }

    // Пункт 2.1, 2.2: Формирование отсортированного кольцевого списка, где |x| > |x - 1|
    List globalList;
#pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        if (fabs(arr[i]) > fabs(arr[i - 1])) {
            Node* newNode = new Node(arr[i]);

            // Первый проход - ищем место без критической секции
            Node* prev = nullptr;
            Node* current = globalList.head;
            bool inserted = false;

            while (current != nullptr && current->value < newNode->value) {
                prev = current;
                current = current->next;
                if (current == globalList.head) {
                    break;  // Возвращаемся в начало списка
                }
            }

            // Если нашли место для вставки, вставляем его в правильное место без критической секции
            if (current != globalList.head && prev != nullptr) {
                prev->next = newNode;
                newNode->next = current;
                inserted = true;
            }

            // Если элемент не был вставлен, выполняем второй проход в критической секции
            if (!inserted) {
#pragma omp critical
                {
                    // Второй проход — вставка в критической секции
                    if (!globalList.head) {
                        // Если список пуст, добавляем первый элемент
                        globalList.head = newNode;
                        newNode->next = globalList.head; // Кольцевое связывание
                    }
                    else {
                        // Ищем место для вставки
                        Node* prev = nullptr;
                        Node* current = globalList.head;
                        while (current != nullptr && current->value < newNode->value) {
                            prev = current;
                            current = current->next;
                            if (current == globalList.head) {
                                break;  // Возвращаемся в начало списка
                            }
                        }

                        // Вставка
                        if (current == globalList.head) {
                            // Вставляем в конец списка
                            prev->next = newNode;
                            newNode->next = globalList.head;
                        }
                        else {
                            // Вставляем между узлами
                            prev->next = newNode;
                            newNode->next = current;
                        }
                    }
                }
            }
        }
    }


    // Пункт 2.3: Нахождение минимального значения

    cout << "Минимальное значение в списке: " << globalList.findMinimum() << endl;


    // Пункт 3: Гистограмма разностей
    vector<int> histogram(numBins, 0);
    float binWidth = 2.0f / numBins;

#pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        float diff = arr[i + 1] - arr[i];
        int binIndex = static_cast<int>((diff + 1.0f) / binWidth);
        if (binIndex >= 0 && binIndex < numBins) {
#pragma omp atomic
            histogram[binIndex]++;
        }
    }

    // Вывод гистограммы
    cout << "\nГистограмма распределения разностей:\n";
    for (int i = 0; i < numBins; ++i) {
        float binStart = -1.0f + i * binWidth;
        float binEnd = binStart + binWidth;
        cout << "[" << binStart << ", " << binEnd << "): " << histogram[i] << "\n";
    }

    auto endTime = omp_get_wtime();
    cout << "\nВремя выполнения: " << endTime - startTime << " секунд\n";

    // Вывод списка
    cout << "\nСписок элементов:\n";
    globalList.printList();

    return 0;
}
