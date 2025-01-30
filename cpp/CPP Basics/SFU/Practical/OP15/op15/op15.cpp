#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
using namespace std;

int N, M, k;

//m - строка 
//n - столбец

void text2bin(std::istream& ist, std::ostream& ost) {
	ist >> N >> M;
	cout << N << " " << M;

	int *arr = new int[1000];
	arr[0] = N;
	arr[1] = M;
	int	i = 2;

	for (int i = 2; (M*N)+2 > i; i++) {
		ist >> arr[i];
		if (i % M-2 == 0) cout << endl;
		if (arr[i] >= 0) cout << " " << arr[i];
		else cout << arr[i];
		ost.write((char*)&arr[i], sizeof(int)); //запись в файл поэлементно
	}
	cout << endl;
	cout << "my task:" << endl;
}

void my_task(std::istream& ost) {
	cout << "введите k: ";
	cin >> k;
	int* arr = new int[(N * M) + 2];
	for (int i = 2; (M * N) + 2 > i; i++) {

		ost.read((char*)&arr[i], sizeof(int));
	}
	int i = M * (k - 1);
	i += 2;
	int task = 0;
	while (i - M - 2 < M * (k - 1)) {
		for (int j = 1; j <= k; j++) {
			if (arr[i] == j) {
				task += 1;
				continue;
			}
		}
		i++;
	}
	
	if (task == M) cout << "Все индексы сошлись!" << endl;
	else cout << "Минимум один индекс не сошелся!";
}

int main() {

	setlocale(0, "");

	ifstream in;
	in.open("ist.txt");
	ofstream out;
	out.open("ost.txt", ios::binary);
	text2bin(in, out);
	out.close();
	ifstream Out;
	Out.open("ost.txt", ios::binary);
	my_task(Out);
}