#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void print_diag(int s) // ����� �������� � "*" �� ���������� S-��� 
{
	int i = 0, a = 0;
	for (i = 1; s >= i; i++) { 
		std::cout << std::string(a, ' '); // ������� a �������� ����� "*"
		printf("*\n"); // \n �����!! "*",
		a += 1;
	}
}
/*
std::string stuff(2, '.');
std::cout << stuff << std::endl;
!! ������ �� �������� !! /\
                         ||
*/

int main() {
	int s;
	setlocale(0, "");

	printf("������� S: ");
	scanf_s("%d", &s);
	print_diag(s);
}