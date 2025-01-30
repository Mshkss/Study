#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x) {
	const double pi = 3.1415926535;
	x = sin(pi * x) * sin(pi * x);
	return x;
}
int main() {

	double a, b, s, y, v, x, scale;
	int u = 0;
	setlocale(0, "");
	cout << "Введите а: " << endl;
	cin >> a;
	cout << "Введите b: " << endl;
	cin >> b;
	cout << "Введите S: " << endl;
	cin >> s;
	cout << "Введите scale:  " << endl;
	cin >> scale;
	cout << endl;

	for (a; a <= b; a += s) {
		x = a + s * u;
		y = f(x);
		v = scale * y;
		cout << setw(scale * y) << "$(" << x << ", " << y << ")" << endl;
	}
}