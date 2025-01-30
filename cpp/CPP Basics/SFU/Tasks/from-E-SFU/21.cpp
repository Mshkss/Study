#include <iostream>
using namespace std;

int splice_array(int arr1[], int arr2[], int len, int arr_out[]) {

    int n1 = 0, n2 = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            arr_out[i] = arr1[n1];
            n1++;
        }
        if (i % 2 != 0) {
            arr_out[i] = arr2[n2];
            n2++;
        }
    }
    for (int m = 0; m < len; m++) cout << arr_out[m] << " ";
    return len;
}

int main()
{
    int len;
    setlocale(0, "");

    cout << "Введите размер массивов arr1 и arr2: " << endl;
    scanf_s("%d", &len);
    int* arr1 = new int[len];
    for (int i = 0; i < len; i++) { 
        cout << "введите элемент массива arr1: " << i << endl;
        scanf_s("%d", &arr1[i]);
    }
    cout << endl;
    int* arr2 = new int[len];
    for (int j = 0; j < len; j++) { 
        cout << "введите элемент массива arr2: " << j << endl;
        scanf_s("%d", &arr2[j]);
    }
    int* arr_out = new int[len];
    len = len * 2;
    int dlin = splice_array(arr1, arr2, len, arr_out);
    cout << "Длина массива 'arr_out' = " << dlin;

}

