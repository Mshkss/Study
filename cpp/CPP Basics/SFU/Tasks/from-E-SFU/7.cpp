// задача про счет количества нулей и едениц 

#include <iostream>
using namespace std;

int find_most_frequent(int a, int b, int c, int d) {
	if (((a + b + c + d) <= 1) && ((a + b + c + d) > 0)) {
		return 0;
	}
	else if (a + b + c + d > 2) {
		return 1;
	}
	else return -1;
}

int main() 
{
	setlocale(0, "");
	int x, y, z, f;
	printf("Введите число A: ");
	scanf_s("%d", &x);
	printf("Введите число B: ");
	scanf_s("%d", &y);
	printf("Введите число C: ");
	scanf_s("%d", &z);
	printf("Введите число D: ");
	scanf_s("%d", &f);
	printf("%d", find_most_frequent(x, y, z, f));
	
}