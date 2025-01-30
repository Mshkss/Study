#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
    double s = 0;
    s = 5 * x + 2;
        return s;
}



int main()
{
    setlocale(0, "");
    double a, aa, b, s;
    cout << "введите а: " << endl;
    cin >> a;
    cout << "введите b: " << endl;
    cin >> b;
    cout << "введите шаг S: " << endl;
    cin >> s;
    cout << endl;

    aa = a;

    for (a; a <= b; a += s) {
        cout.width(15);
        cout << setprecision(3) << fixed << a << "  ";
       
    }
    cout << endl;
    for (aa; aa <= b; aa += s) {
        cout.width(15);
        cout << setprecision(5) << scientific << f(aa) << "  ";
    }
}

