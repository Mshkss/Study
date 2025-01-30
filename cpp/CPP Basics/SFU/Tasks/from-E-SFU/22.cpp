#include <iostream>
#include <random>

using namespace std;

void print_array(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << *(arr+i) << endl;
	}
}

int main() {

	setlocale(0, "");

	int n, len;
	cout << "Введите длину массива arr: ";
	cin >> n;
	int* p_mas = new int[n];
	
	for (int i = 0; i < n; i++) {
		 *(p_mas + i) = rand() % 50-100;
	}
	
	cout << "Введите сколько нужно вывести первых элементов массива arr: ";
	cin >> len;

	print_array(p_mas, len);


}