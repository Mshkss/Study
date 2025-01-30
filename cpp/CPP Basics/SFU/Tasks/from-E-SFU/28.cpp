#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void rstrip(char* s, char* chars) {
	int lenCH = strlen(chars),
		lenS = strlen(s);

	for (int i = 0; i < lenCH; i++) {
		for (int j = 0; j <= lenS+1;j++){
			if (chars[i] == s[j]) {
				chars[i] = ' ';
				//strcpy(chars," ");
				
				cout << chars[i] << " - reply! ";
			}
			else
				continue;
		}
	}
	cout << endl;
	cout << chars;
}


int main() {
	setlocale(0, "");

	char* chars = new char[100];
	cout << "Введите строку chars: " << endl;
	cin.getline(chars, 100);

	char* s = new char[100];
	cout << "Введите символы, которые нужно удалить из строки chars: " << endl;
	cin.getline(s, 100);
	
	rstrip(s, chars);
	
	return 0;
}