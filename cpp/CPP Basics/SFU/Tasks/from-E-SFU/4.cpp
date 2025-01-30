#include <iostream>

int main()
{	
	double x, a, b, c, d;
	setlocale(0, "");	

	printf("Введите число X: ");
	scanf_s("%lf", &x);
	printf("Введите число A: ");
	scanf_s("%lf", &a);
	printf("Введите число B: ");
	scanf_s("%lf", &b);
	printf("Введите число C: ");
	scanf_s("%lf", &c);
	printf("Введите число D: ");
	scanf_s("%lf", &d);

	if (a < b && c < d) {

		if ((x >= a && x <= b) || (x >= c && x <= d))
			printf("true");
		else
			printf("false");
		return 0;

	}
	else printf("ошибка");
}