#include <iostream>
#include <cmath>   
#include <stdio.h>

int main() {
    double x;
    setlocale(0, "");

    printf("Введите число:");
    scanf_s("%lf", &x);
    int d;
    if (x > 0)
        d = (int)floor(10 * x) % 10;
    else
        d = abs((int)ceil(10 * x) % 10);
    printf("%d", d);
    
    return 0;
}
