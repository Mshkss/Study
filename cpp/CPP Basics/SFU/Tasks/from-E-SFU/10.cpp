#include <iostream>
#include <cmath>
#include <conio.h> // хз что это
#include <stdio.h> // и это

int main()
{
    int x, c;
    setlocale(0, "");
    c = 0;
    printf("Введите X");
    scanf_s("%d", &x);
    printf("%d", x);
    while(x>c) {
        c = x;
        printf("\nВведите x : ");
        scanf_s("%d", &x);
        printf("%d", x);
       
    }
}






