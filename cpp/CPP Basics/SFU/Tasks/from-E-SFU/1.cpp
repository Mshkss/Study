#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	int a, b;
	setlocale(0, "");

	printf("Введите значение переменной 'a' \n");
	scanf_s("%d", &a);
	printf("Введите значение переменной 'b' \n");
	scanf_s("%d", &b);
	if (a == b) printf("Переменные не могут быть одинаковыe. Введите a и b повторно \n"); 
	
	else
	{
		printf("Значение переменной 'a' = %d \n", a);
		printf("Значение переменной 'b' = %d \n", b);
		a = abs(a + b);
		b = abs(b - a);
		a = abs(a - b);
		printf("Новое значение переменной 'a' = %d \n", a);
		printf("Новое значение переменной 'b' = %d \n", b);
	}
}