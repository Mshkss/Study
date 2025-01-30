#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {

	ofstream out("out.txt");
	setlocale(0, "");
	size_t nrows, ncols;
	cout << "Введите количество столбцов (Затем нажмите клавишу 'Enter')" << endl;
	cin >> nrows;
	cout << "Введите количество строк (Затем нажмите клавишу 'Enter')" << endl;
	cin >> ncols;
	int* mas = new int[nrows];
	int** arr = new int* [nrows];
	for (int i = 0; i < nrows; i++)
	{
		arr[i] = new int[ncols];
		cout << "Вводим " << i + 1 << " строку" << endl;
		for (int j = 0; j < ncols; j++) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "Исходный массив:" << endl;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			out << setw(3) << arr[i][j];
		}
		out << endl;
	}
	cout << endl << "Результат в файле 'out.txt'";
	out.close();
}