#include <iostream>
#include <cmath>

int main() {
	double a,b,c,d, x1, x2;
	setlocale(0, "");

	printf("Введите a: ");
	scanf_s("%lf", &a);
	printf("Введите b: ");
	scanf_s("%lf", &b);
	printf("Введите c: ");
	scanf_s("%lf", &c);

	d = sqrt(b * b - 4 * a * c);
	printf("\nd = %lf",d);
	x1 = ((-b) - d) / (2 * a);
	x2 = ((-b) + d) / (2 * a);
	if (d > 0) {
		printf("\nx1 = %lf", x1);
		printf("\nx2 = %lf", x2);
	}
	else if (d == 0) {
		printf("\nx1 = %lf", x1);
	}
	else
		printf("\nв уравнении нет действительных корней");
	return 404;
}