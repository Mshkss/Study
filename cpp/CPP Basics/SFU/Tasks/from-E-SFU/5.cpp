#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a1, a2, b1, b2;
	setlocale(0, "");

	printf("Введите a1: ");
	scanf_s("%lf", &a1);
	printf("Введите a2: ");
	scanf_s("%lf", &a2);
	printf("Введите b1: ");
	scanf_s("%lf", &b1);
	printf("Введите b2: ");
	scanf_s("%lf", &b2);

	
	if (a1 == b1 && a2 == b2) {
		printf("A = B");
		return 1;
	}
	else if (a1 > b1 && a2 < b2) {
		printf("А внутри отрезка В");
		return 2;
	}
	else if (b1 > a1 && b2 < a2) {
		printf("В внутри отрезка А");
		return 3;
	}
	else if ((b2<= a2 and a1 >=b1 ) || (a2<=b2 and a1<=b1) ) {
		printf("Другое пересечение");
		return 4;
	}
	else
		printf("Нет пересечения");
		
		
		
		
		
		
return 404;
}