#include <iostream>

using namespace std;

double pow_(int i, float x) {
    float s = 1;
    for (int j = 1; j <= i; j++) {
        s *= x;
    }
    return s;
}

int main()
{
    int n;
    float x,sumsum=1;

    scanf_s("%d", &n);
    scanf_s("%f", &x);

    for (int i = 1; i <= n; i++) {
        sumsum *= 2 * pow_(i, x);



    }
    cout << sumsum;
}