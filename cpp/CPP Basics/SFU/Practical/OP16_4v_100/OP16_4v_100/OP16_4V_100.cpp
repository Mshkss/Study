#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct user_access
{
	char last_name[20];
	char login[20];
	char user_password[20];
	bool access;
};

user_access* load_txt(istream& in, size_t len) {
	user_access* str = new user_access[len];
	while (!in.eof()) {
		for (int i = 0; i < len; i++) {
			in >> str[i].last_name >> str[i].login >> str[i].user_password >> str[i].access;
		}
	}
	return str;
}

void print_data(const user_access* data, size_t len, ofstream& ost) {
	for (int i = 0; i < len; i++) {
		cout << data[i].last_name << " " << data[i].login << " " << data[i].user_password << " " << data[i].access << endl;
	}
}
void save_bin(user_access* data, std::size_t len, std::ofstream& ost) {
	cout << "save_bin" << endl;
	for (int i = 0; i <= len; i++) {
		if (strncmp(data[i].last_name, data[i + 1].last_name, 1) > 0) {
			i = 0;
			swap(data[i].last_name, data[i + 1].last_name); // <-- почему то не работает???
		}
		else if (strncmp(data[i].last_name, data[i + 1].last_name, 1) <= 0) break;
		else
			continue;
	}
	for (int i = 0; i < len; i++) {
		cout << data[i].last_name << " " << data[i].login << " " << data[i].user_password << " " << data[i].access << endl;
	}
}

int main() {
	setlocale(0, "");

	size_t n = 6;

	ifstream in("in.txt");
	ofstream out("out.txt", ios::binary);

	user_access* str = new user_access[n];


	int mode;
	cin >> mode;
	switch (mode)
	{
	case 1: {
		str = load_txt(in, n);
		print_data(str, n, out);
		save_bin(str, n, out);
		break;


	}
	case 2: {


	}
	default: cout << "неккоректный ввод!" << endl;
		break;
	}



	//load_bin(ost)
}