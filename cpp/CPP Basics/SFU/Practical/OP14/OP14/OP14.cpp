#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void join(istream& in, ostream& out) {

	string buf, str1;
	string* s = new string[100];

	while (!in.eof()) {
		getline(in, buf);
		str1 += buf;
		str1 += " ";
	}
	int j = 0;
	for (int i = 0; i < str1.length(); i++) {
		
		
		cout << endl;
		cout << "цикл I - " << i << endl;
		cout << endl;



		if (i == 0) {
			if (str1[i] == '.' and (str1[i + 1] == ' ' or (str1[i + 1] == in.eof()))) {
				while (j < 3) {
					cout << "цикл j - " << j << endl;

					*(s + j) = '.';
					out << *(s + j);
					j++;
				}
				cout << "выход из цикла j" << endl;
				j = 0;
			}
			else {
				cout << "нулевое сложение строк " << str1[i] << endl;
				*(s + i) = str1[i];
				out << *(s + i);
				continue;
			}
		}
		else {
			if (str1[i] == '.' and (str1[i + 1] == ' ' or (str1[i + 1] == in.eof())) and (str1[i - 1] == ' ')) {
				while (j < 3) {
					cout << "цикл j - " << j << endl;

					*(s + j) = '.';
					out << *(s + j);
					j++;
				}
				cout << "выход из цикла j" << endl;
				j = 0;
			}
			else {
				cout << "ненулевое сложение строк" << endl;
				*(s + i) = str1[i];
				out << *(s + i);
				continue;
			}
		}
	}
}

int main()
{
	setlocale(0, "");
	ifstream in("in.txt");
	ofstream out("out.txt");
	cout << "console.log: " << endl;
	join(in, out);
	cout << endl;
	cout << "Результаты записаны!";
	out.close();
}