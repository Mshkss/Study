#include <iostream>
#include <chrono>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <thread>

using namespace std;

void slow(int N) {

	auto begin = std::chrono::steady_clock::now();
	int a = 0;
	int k = 0;
	for (int i = 0; i < N; ++i) {
		a += i;
		for (int j = 0; j < N; ++j) {
		}
		k += a;
	}

	auto end = std::chrono::steady_clock::now();
	cout << "k = " << k << endl;

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " nsec\n";
}

void fast(int N) {


	auto begin = std::chrono::steady_clock::now();
	int a = 0;
	int k = 0;
	for (int i = 0; i < N; ++i) {
		a += i;
		k += a;
	}

	auto end = std::chrono::steady_clock::now();
	cout << "k = " << k << endl;

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " nsec\n";
}

int main() {

	cout << "1 (slow) / 2 (fast): " << endl;
	int mode;
	cin >> mode;
	int N;
	cout << "N = ";
	cin >> N;
	switch (mode)
	{
	case 1: {
		slow(N);
		break;
	}
	case 2: {
		fast(N);
		break;
	}
	default: {
		cout << "error!" << endl;
		break;
	}
	}
}