#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void join(const char* sep, istream& ist, ostream& ost) {

	string buf, str;
	while (!ist.eof()) {
		getline(ist, buf);
		str += buf;
		str += " ";
	}
	for (int i = 0; i < str.length(); i++) {

		if (str[i] != ' ') ost << str[i];
		if (str[i] == ' ' && str[i - 1] != ' ' && i!=str.length()-1) ost << sep;

	}
}

int main()
{
    setlocale(0, "");
    ifstream ist("ist.txt");
    ofstream ost("ost.txt");

    char sep[255];
    cout << "введите sep: " << endl;
    cin.getline(sep, 255);
    join(sep, ist, ost);
    ost.close();
}