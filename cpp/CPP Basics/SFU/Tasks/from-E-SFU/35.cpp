#include <iostream>
#include <fstream>

using namespace std;

void fliplr(int arr[][100], size_t nrows, size_t ncols, std::ostream& ost) {

	for (int i = 0; i < nrows; i++) {
		cout << endl;
		if(i != 0)ost << endl;
		for (int j = ncols - 1; j >= 0; j--) {
			cout << arr[i][j];
			cout << " ";
			ost << arr[i][j];
			ost << " ";
		}
	}
}

int main() {

	setlocale(0, "");
	ofstream out("ost.txt");

	int nrows;
	cout << "введите nrows: " << endl;
	cin >> nrows;

	int ncols;
	cout << "введите ncols: " << endl;
	cin >> ncols;

	int mas[10][100]{};
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++) {
			cin >> mas[i][j];
		}
	fliplr(mas, nrows, ncols,out);
}