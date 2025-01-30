#include <iostream>
#include <random>
using namespace std;

void sort(float arr[], int len, bool asc) {
	if (asc) {
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	else {
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					float buf = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = buf;
				}
			}
		}
	}
	for (int k = 0; k < len; k++)
		cout << arr[k] << " ";
}

int main() {
	setlocale(0, "");

	bool asc = 1;
	cout << "введите asc (true или false, где true = 1, false = 0): ";
	cin >> asc;

	int len;
	cout << "введите длину массива: ";
	cin >> len;
	
	float* arr = new float[len];
	for (int i = 0; i < len; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	sort(arr, len, asc);
}