#include <iostream>
#include <random>

using namespace std;


void findmax(int maxarr) {
	int arr[100]{};
	int a, max = 0;
	
	cout << endl;

	for (int i = 0; i < maxarr; i++) {
		arr[i] = rand() % (-50+100);
		cout << arr[i] << endl;

}
	for (int j = 0; j < maxarr; j++) {
		if (arr[j] > arr[j + 1])
			if (max < arr[j])
				max = arr[j];
		
	}

	cout << "max = " << max;
}

int my_task(int A[], int lenA, int B[], int lenB) {
	cout << "my task" << endl;
	for (int i = 0; i < lenA; i++) {
		A[i] = rand() % 10 - 5;
		cout << A[i] << endl;

	}
	for (int i = 0; i < lenA; i++) {
		if (A[i] < 0) A[i] = B[i];
		cout << "замененный элемент массива A элементом массива B равен: " << A[i] << endl;
	}

	return 1;
}


void print_array(int arr[], int len) {
	for(int i = 0; i < len; ++i)
	cout << "Элемент массива I: " << arr[i] << endl;
}

int *read_array(int len) {
	int arr[1000]{};
	for (int i = 0; i < len; ++i) {
		arr[i] = i;
	}
	print_array(arr, len);
	return arr;
}


int main() {
	setlocale(0, "");
	int len, max;
	cout << "введите длину массива" << endl;
	cin >> len;
	int* mas = new int[len];
	mas = read_array(len);

	int lenA, lenB;
	int A[100]{},
		B[100]{};

	cout << "введите длину массива A: " << endl;
	cin >> lenA;
	cout << "введите длину массива B: " << endl;
	cin >> lenB;
	for (int i = 0; i < lenA; ++i) {
		A[i] = i;
	}
	for (int i = 0; i < lenB; ++i) {
		B[i] = i;
	}

	//int* masA = new int[A],
	//int* masB = new int[B];
	my_task(A, lenA, B, lenB);

	cout << endl;
	cout << "findmax(): " << endl;

	cout << "введите длину массива findmax";	
	cin >> max;
	findmax(max);

}