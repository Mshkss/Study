#include <iostream>
#include <cmath>	
using namespace std;

double f1(double x) {

	double a;
	a = (exp(2*x)) - (2, 19 * (pow(10, 6))); // хз что тут надо написать, и как попять что написал правильно эту шляпу
	return a;								 // но в целом ответ вроде есть, правильный или нет, я не знаю xd
}											 // вариант 4, 100%

double f2(double x) {
	
	return pow(((5*x)+2),1/3);
}

int main()
{
	double x;
	setlocale(0, "");

	printf("Введите x: ");
	scanf_s("%lf", &x);

	printf("%lf", f1(x) + f2(x));
}