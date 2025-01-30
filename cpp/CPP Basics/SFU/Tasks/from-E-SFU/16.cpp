#include <iostream>

using namespace std;

double f(double x) {
    double s = 0;
    s = 1*x
    return s;
}



int main()
{
    setlocale(0, "");
    double a, b, s;
    cout << "введите а: " << endl;
    cin >> a;
    cout << "введите b: " << endl;
    cin >> b;
    cout << "введите шаг S: " << endl;
    cin >> s;
    cout << endl;

    for (a; a <= b; a + s) {
        cout.width(10);
        cout << fixed << a;
        cout << "   " << scientific << f(a) << endl;
        a += s;
    }

}
