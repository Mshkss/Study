#include <stdio.h>

int main() {
    int number;
    printf("Введите число: ");
    scanf("%d", &number);
    
    int square = number * number;
    
    printf("Квадрат числа %d равен %d\n", number, square);
    
    return 0;
}

