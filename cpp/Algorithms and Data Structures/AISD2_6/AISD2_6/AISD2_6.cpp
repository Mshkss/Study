#include <iostream>
#include <cmath>

// Функция для нахождения пропущенного элемента в геометрической прогрессии
int findMissingElement(int arr[], int n) {
    // Находим общее отношение прогрессии
    int commonRatio = pow(arr[n - 1] / arr[0], 1.0 / n);

    // Ищем пропущенный элемент
    for (int i = 1; i < n; i++) {
        if (arr[i] / arr[i - 1] != commonRatio) {
            return arr[i - 1] * commonRatio;
        }
    }

    return -1; // Если пропущенный элемент не найден
}

int main() {
    setlocale(0, "");
    int arr[] = { 2, 6, 18, 25, 54 };
    int n = sizeof(arr) / sizeof(arr[0]) + 1;

    int missingElement = findMissingElement(arr, n);
    if (missingElement != -1) {
        std::cout << "Пропущенный элемент: " << missingElement << std::endl;
    }
    else {
        std::cout << "Пропущенный элемент не найден" << std::endl;
    }

    return 0;
}