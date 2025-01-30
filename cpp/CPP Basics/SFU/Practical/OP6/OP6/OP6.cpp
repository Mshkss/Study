#include <cmath>
#include <iostream>

using namespace std;

/*/double pow_(double x, int n) {

	double s = 1;
	for (n; n > 0; n--) 
	{ 
		s *= (x - 1);
	}
	return s;
}
*/


int main()
{
	setlocale(0, "");

	double x, i = 1, s = 0;
	float razn;

	

	double to4nost, chisl, buf;
	int dlya_while = 0, n = 1, znam;

	

	std::cout << "введите точность: " << endl;
	scanf_s("%lf", &to4nost);	
	std::cout << "введите x: " << endl;
	scanf_s("%lf", &x);
			
	while (dlya_while != 1) {
		chisl = pow(x-1, n);
		if (n % 2 == 0) znam = n * (-1);
		else znam = n;
		buf = chisl / znam ;
		if (abs(buf - s) < to4nost)
			dlya_while +=1;
		else {
			s += buf;	
			n++;
			
		}
	}
	
	
	
	
	razn = (std::log(buf) - buf);
	std::cout << "сумма ряда равна: " << buf << endl;
	std::cout << "Значение мат функции равно: " << std::log(buf) << endl;
	std::cout << "разность равна: " << razn << endl;

}