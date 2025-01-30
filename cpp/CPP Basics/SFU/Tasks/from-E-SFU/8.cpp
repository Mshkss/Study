#include <iostream>
#include <cmath>
using namespace std;

float dist(float x1, float y1, float x2, float y2){
    float d;
    d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    return d;
}

int main()
{
    float x1, y1, x2, y2;
    setlocale(0, "");
    printf("Введите x1 = ");
    scanf_s("%f", &x1);
    printf("Введите y1 = ");
    scanf_s("%f", &y1);
    printf("Введите x2 = ");
    scanf_s("%f", &x2);
    printf("Введите y2 = ");
    scanf_s("%f", &y2);
    printf("%f", dist(x1, y1, x2, y2));
}
