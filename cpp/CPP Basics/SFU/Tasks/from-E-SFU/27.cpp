#include <iostream>
#include <algorithm>
using namespace std;
void sort(float arr[], int len, float x) {

	float* dist = new float[len];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++)
		{
			if (abs(arr[j] - x) > abs(x - arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	
	}
	for (int l = 0; l < len; l++) dist[l] = abs(x - arr[l]);
	for (int f = 0; f < len; f++) cout << arr[f] << " ";
	cout << endl <<endl;
	for (int m = 0; m < len; m++) cout << dist[m] << " ";
}
int main() {
	setlocale(0, "");
	float len;
	cout << "Введите длину массива 'arr' (Затем нажмите клавишу 'Enter')" << endl;
	cin >> len;
	float* arr = new float[len];
	for (int i = 0; i < len; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	float x;
	cout << "Задайте значение переменной 'x' (Затем нажмите клавишу 'Enter')" << endl;
	cin >> x;
	cout << endl;
	sort(arr, len, x);
}