#include <iostream>	
#include <random>

using namespace std;

int count_equal(int* arr, int len, int x) {
	int c = 0;

	for (int i = 0; i < len; i++) {
		cout << *(arr + i) << endl;
		if (*(arr + i) == x)
			c += 1;
	}
	cout << "x = " << c;
	return c;
}

int main() {
	
	setlocale(0, "");

	int x, len, n;

	cout << "Введите количество элементов массива: ";
	cin >> n;

	int* pr_mas = new int[n];


	cout << "Введите len: ";
	cin >> len;
	cout << "Введите X: ";
	cin >> x;

	for (int i = 0; i < n; i++) {
		*(pr_mas + i) = rand() %  5;
	}

	count_equal(pr_mas, len, x);
}