#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void findmax(int maxarr) {
	int *arr = new int[maxarr];
	int max = 0;

	cout << endl;

	for (int i = 0; i < maxarr; i++) {
		*(arr+i) = rand() % (-50 + 100);
		cout << *(arr+i) << endl;

	}
	for (int j = 0; j < maxarr; j++) {
		if (*(arr+j) > *(arr + j + 1))
			if (max < *(arr+j))
				max = *(arr+j);

	}
	cout << "max = " << max;
}

int my_task(int *arrA, int lenA, int *arrB, int lenB) {
	cout << "my task" << endl;
	for (int i = 0; i < lenA; i++) {
		*(arrA+i) = rand() % 10 - 5;
		cout << *(arrA+i) << endl;

	}
	for (int i = 0; i < lenA; i++) {
		if (*(arrA+i) < 0) *(arrA+i) = *(arrB+i);
		cout << "замененный элемент массива A элементом массива B равен: " << *(arrA+i) << endl;
	}
	return 1;
}


void print_array(int* arr, int len) {
	for (int i = 0; i < len; ++i)
		cout << "Элемент массива I: " << *(arr + i) << endl;
}

int* read_array(int len) {
	int* arr = new int[len];

	for (int i = 0; i < len; ++i) {
		*(arr + i) = rand() % 5;
	}
	print_array(arr, len);
	return 0;
}

int main() {
	setlocale(0, "");
	int len, max;
	cout << "введите длину массива" << endl;
	cin >> len;
	int* mas = new int[len];
	mas = read_array(len);

	int lenA, lenB;


	cout << "введите длину массива A: " << endl;
	cin >> lenA;
	cout << "введите длину массива B: " << endl;
	cin >> lenB;

	int* arrA = new int[lenA],
		*arrB = new int[lenB];

	for (int i = 0; i < lenA; ++i) {
		*(arrA + i) = rand() % 10;
	}
	for (int j = 0; j < lenB; ++j) {
		*(arrB + j) = rand() % 10;
	}

	//int* masA = new int[A],
	//int* masB = new int[B];
	my_task(arrA, lenA, arrB, lenB);

	cout << endl;
	cout << "findmax(): " << endl;

	cout << "введите длину массива findmax";
	cin >> max;
	findmax(max);
}