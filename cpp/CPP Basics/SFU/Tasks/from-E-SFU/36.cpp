#include <iostream>
#include <fstream>
using namespace std;

void transpose(int arr[100][100], size_t size, std::ostream& ost) {
	for (int i = 0; i < size; i++) {
		cout << endl;
		if(i!=0)ost << endl;
		for (int j = 0; j < size; j++) {
			cout << arr[j][i];
			ost << arr[j][i];
		}
	}
}

int main() {

	setlocale(0, "");
	ofstream ost("ost1.txt");
	
	int size;
	cout << "введите размерность матрицы size:" << endl;
	cin >> size;
	cout << endl;
	int arr[100][100]{};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}
	transpose(arr, size,ost);
}