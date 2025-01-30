#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void rstrip(char* chars) {
	int lenCH = strlen(chars),
		c = 0,
		cmax = 0;

	for (int i = 0; i < lenCH; i++) {
		if (chars[i] == ' ') {
			c += 1;
			if (cmax < c) {
				cmax = c;
			};
		}
		else {
			c = 0;
			continue;
		}
	}
	cout << endl;
	cout << "Максимальное количество пробелов = " << cmax;
}


int main() {
	setlocale(0, "");

	char* chars = new char[100];
	cout << "Введите строку chars: " << endl;
	cin.getline(chars, 100);


	rstrip(chars);

	return 0;
}