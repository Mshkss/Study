#include <iostream>

using namespace std;

int** make2d(size_t nrows, size_t ncols, int val) {
	
	int* mas1 = new int[nrows];
	int** mas2 = new int* [ncols];
	for (int i = 0; i < ncols; i++) {
		mas2[i] = new int[nrows];
		for (int j = 0; j < nrows; j++) {
			mas2[i][j] = val;
		}
	}
	return mas2;
}

int main() {
	setlocale(0, "");

	size_t nrows;
	cout << "Введите nrows: " << endl;
	cin >> nrows;

	size_t ncols;
	cout << "Введите ncols: " << endl;
	cin >> ncols;

	int val;
	cout << "Введите val: " << endl;
	cin >> val;

	int** Mas = make2d(nrows, ncols, val);
	for (int m = 0; m < ncols; m++) {
		for (int k = 0; k < nrows; k++) {
			cout << Mas[m][k] << " ";
		}
		cout << endl;
	}
}