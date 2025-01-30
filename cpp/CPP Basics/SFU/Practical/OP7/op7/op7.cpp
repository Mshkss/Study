#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
	float func;
	func = x * sin(3 * x) - 2;
	return func;
}

int main()
{
	setlocale(0,"");
	int t = 0;
	float a, b, h;
	cin >> a >> b >> h;
	for (a; a <= b; a += h) {
		cout << "Значение функуии" << " " << "=" << " " << f(a) << endl;
		if (f(a) < 0 && f(a + h) >= 0) {
			t += 1;
		}
		else if (f(a) >= 0 && f(a + h) < 0) {
			t += 1;
		}
	}
	cout << endl << "Количество отрезков на концах которых разные знаки" << " " << "=" << " " << t;
	return 0;
}