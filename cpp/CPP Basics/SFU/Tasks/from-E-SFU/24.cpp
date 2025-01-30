#include <random> 
#include <iostream>

using namespace std;

int splice_array(int* arr1, int* arr2, int len, int* arr_out) {

    int n1 = 0, n2 = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            *(arr_out + i) = *(arr1 + n1);
            n1++;
        }
        if (i % 2 != 0) {
            *(arr_out + i) = *(arr2 + n2);
            n2++;
        }
    }
    for (int m = 0; m < len; m++) cout << *(arr_out + m) << " ";
    return len;
}


int main()
{
    setlocale(0, "");

    int len;

    cout << "введите len: ";
    cin >> len;

    int* arr1 = new int[len],
        * arr2 = new int[len];

    for (int i = 0; i < len; i++) {
        cout << i << "= ";
        cin >> *(arr1 + i);
    }

    for (int j = 0; j < len; j++) {
        cout << j << "= ";
        cin >> *(arr2 + j);
    }

    len *= 2;
    int* arr_out = new int[len];
    cout << endl;
    int dlin = splice_array(arr1, arr2, len, arr_out);
    cout << "Длина массива 'arr_out' = " << dlin;
    
}