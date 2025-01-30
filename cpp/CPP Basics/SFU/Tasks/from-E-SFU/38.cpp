#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void rev_lines(std::istream& ist, std::ostream& ost) {

	char str[255][255];
	int i = 0;
	while (!ist.eof()) {
		ist.getline(str[i], 255);
		i++;
	}
	for (int j = i; j > 0; j--)
	ost << str[j-1] << endl;

}

int main() {
	setlocale(0, "");

	ifstream ist("ist.txt");
	ofstream ost("ost.txt");
	rev_lines(ist, ost);
	ost.close();
	cout << "Результат программы в текстовом файле 'ost.txt'" << endl;
}