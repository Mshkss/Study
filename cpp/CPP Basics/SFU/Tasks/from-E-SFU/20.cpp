#include <iostream>
using namespace std;    

int count_equal(int arr[], int len, int x) {
    int k = 0;
    for (int i = 0; i < len ; i++) {
        if (arr[i] == x) {
            k += 1;
        }
        cout << arr[i] << " ";
        }
    cout << endl;
    cout << k << " совпадений x" << endl;
    return k;
}


int main()
{
    int  arr[100]{},
        i,x,
        len;

    setlocale(0, "");

    cout << "введите x: " << endl;
    scanf_s("%d", &x);
    cout << "сколько вывести первых элементов массива: " << endl;
    scanf_s("%d", &len);

    for (i = 0; i <= 5; i++) { // тут менять массив
        cout << "введите элемент массива " << i << endl;
        scanf_s("%d", &arr[i]);
    }
    count_equal(arr, len, x);
}