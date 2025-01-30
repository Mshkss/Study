#include <iostream>
#include <algorithm>
using namespace std;
void sort(int arr[], int len, bool even_greater) {

	int* otsort = new int[len];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	if (even_greater) {
		int s = 0;
		for (int k = 0; k < len; k++) {
			if (arr[k] % 2 != 0) {
				otsort[s] = arr[k];
				s++;
			}
		}
		for (int k = 0; k < len; k++) {
			if (arr[k] % 2 == 0) {
				otsort[s] = arr[k];
				s++;
			}
		}
	}
	else {
		int s = 0;
		for (int k = 0; k < len; k++) {
			if (arr[k] % 2 == 0) {
				otsort[s] = arr[k];
				s++;
			}
		}
		for (int k = 0; k < len; k++) {
			if (arr[k] % 2 != 0) {
				otsort[s] = arr[k];
				s++;
			}
		}
	}
	for (int m = 0; m < len; m++) cout << otsort[m] << " ";
}
int main() {
	setlocale(0, "");
	int len;
	cout << "Введите длину массива 'arr' (Затем нажмите клавишу 'Enter')" << endl;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	bool even_greater;
	cout << "Задайте значение 'true (1)' или 'false (0)' переменной 'asc' (Затем нажмите клавишу 'Enter')" << endl;
	cin >> even_greater;
	sort(arr, len, even_greater);
}