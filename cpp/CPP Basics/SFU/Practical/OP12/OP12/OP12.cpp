#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	setlocale(0, "");

	char* ch = new char[10];
	cout << "введите координаты фигуры: " << endl;
	cin.getline(ch, 3);
	float len = strlen(ch);
	if (len > 2) return 1;

	int x = 1, y = 1;
	for (int i = 0; i < len; ++i) {
		if (*(ch + i) == 'A') x = 1;
		else if (*(ch + i) == 'B') y = 2;
		else if (*(ch + i) == 'C') y = 3;
		else if (*(ch + i) == 'D') y = 4;
		else if (*(ch + i) == 'E') y = 5;
		else if (*(ch + i) == 'F') y = 6;
		else if (*(ch + i) == 'G') y = 7;
		else if (*(ch + i) == 'H') y = 8;
		else {
			cout << "error!";
			return 10;
		}
		i++;	
	}
	for (int i = 1; i <= len; ++i) {
		if (*(ch + i) == '8') x = 8;
		else if (*(ch + i) == '7') x = 7;
		else if (*(ch + i) == '6') x = 6;
		else if (*(ch + i) == '5') x = 5;
		else if (*(ch + i) == '4') x = 4;
		else if (*(ch + i) == '3') x = 3;
		else if (*(ch + i) == '2') x = 2;
		else if (*(ch + i) == '1') x = 1;
		else {
			cout << "error!";
			return 11;
		}
		i++;
	}
	char mas[8][8]{};
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			mas[i][j] = '.';
		}
	}
	for (int j = 0; j <= 7; j++) {
		int i = x - 1;
		mas[i][j] = '*';
		for (int i = 0; i <= 7; i++) {
			int j = y - 1;
			mas[i][j] = '*';
		}
	}
	mas[x - 1][y - 1] = 'L';				//i j = ладья
	for (int i = 0; i <= 7; i++) {
		cout << endl;
		for (int j = 0; j <= 7; j++) {
			cout << " ";
			cout << mas[i][j];
		}
	}
	cout << endl;
}