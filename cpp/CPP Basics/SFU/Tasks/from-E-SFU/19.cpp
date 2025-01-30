#include <iostream>

using namespace std;

void print_array(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}

int main()
{
    int  arr[10],
        i,
        len;

    setlocale(0, "");
    
    
    //cout << "введите кол-во элементов массива: " << endl;
    //scanf_s("%d", &n);
    cout << "сколько вывести первых элементов массива: " << endl;
    scanf_s("%d", &len);

    for (i = 0; i <= 5; i++){
        cout << "введите элемент массива " << i << endl;
        scanf_s("%d", &arr[i]);
    }
    print_array(arr, len);
}

