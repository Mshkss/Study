#include <iostream>
#include <cmath>
using namespace std;
float min_or_max(float a, float b, float c) {   
    if (a > (0.5)) {
        return max(b, c);
    }
    else return min(b, c);
}

int main()
{
    setlocale(0, "");
    float a, b, c;
    printf("Введите число А: ");
    scanf_s("%f", &a);
    printf("Введите число B: ");
    scanf_s("%f", &b);
    printf("Введите число C: ");
    scanf_s("%f", &c);
    printf("число равно %f ", min_or_max(a,b,c));
}