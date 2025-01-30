#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void print_diag(int s) // вывод пробелов и "*" по введенному S-раз 
{
	int i = 0, a = 0;
	for (i = 1; s >= i; i++) { 
		std::cout << std::string(a, ' '); // выводит a пробелов перед "*"
		printf("*\n"); // \n после!! "*",
		a += 1;
	}
}
/*
std::string stuff(2, '.');
std::cout << stuff << std::endl;
!! почему не работает !! /\
                         ||
*/

int main() {
	int s;
	setlocale(0, "");

	printf("¬ведите S: ");
	scanf_s("%d", &s);
	print_diag(s);
}