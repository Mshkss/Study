#include <iostream>

using namespace std;

bool truefalse(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 or n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 or n % (i + 2) == 0)
			return false;

	return true;
}

void ez(int n)
{
	for (int i = 2; i <= n; i++) {
		if (truefalse(i))
			cout << i << endl;
	}
}

int main()
{
	setlocale(0, "");	
	int n;
	
	printf("Введите N: ");
	scanf_s("%d", &n);
	
	ez(n);
}