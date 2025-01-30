#include <iostream>
using namespace std;    

int main()
{
    setlocale(0, "");
    int sum = 0, i = 1;
    int N;

    cout << "Введите N :" << endl;
    scanf_s("%d", &N);

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum += i * 1;
        }
        else  sum += -1 * i;
    }
    cout << sum << endl;
}