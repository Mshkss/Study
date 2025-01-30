
#include <iostream>
using namespace std;
int func(int A[], int B[], int lenA, int lenB, int i) {
	int t = 0;
	int* C = new int[lenA];
	for (i; i < lenA;) {
		for (int i1 = 0; i1 < lenB; i1++) {
			if (A[i] == B[i1]) {
				t += 1;
			}
			else { t += 0; }
		}
		C[i] = t;
		t = 0;
		return C[i];
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int len, len1;
	string t;
	cout << "Введите длину 1-ого массива" << endl;
	cin >> len;
	int* A = new int[len];
	int* C = new int[len];
	cout << "Введите длину 2-ого массива" << endl;
	cin >> len1;
	int* B = new int[len1];
	cout << "Введите элементы 1-ого масива" << endl;
	for (int i = 0; i < len; i++) {
		cin >> A[i];
	}
	cout << "Введите элементы 2-ого масива" << endl;
	for (int i1 = 0; i1 < len1; i1++) {
		cin >> B[i1];
	}
	cout << "Ввидете тип сортировки (decrease / growth)" << endl;;
	cin >> t;
	for (int i = 0; i < len; i++) {
		C[i] = func(A, B, len, len1, i);
		cout << func(A, B, len, len1, i) << " ";
	}
	if (t == "growth") {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len - 1 - i; j++) {
				if (C[j] > C[j + 1]) {
					swap(C[j], C[j + 1]);
				}
			}
		}
	}
	else if (t == "decrease") {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len - 1 - i; j++) {
				if (C[j] < C[j + 1]) {
					swap(C[j], C[j + 1]);
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << C[i] << " ";
	}
	return 0;
}