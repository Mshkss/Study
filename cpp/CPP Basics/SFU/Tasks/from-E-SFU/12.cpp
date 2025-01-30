#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

void print_rect(int x, int y, int sx, int sy) {

	int i = 0;		// подсчет количества строчек Y
	while (y > i)
	{
		if (i == 0) {
			printf(" ");
		}
		else
			printf("\n ");
		i = i + 1;

	}			// подсчет количества столбов X
	i = 0;
	while ((x - 1) > i) {

		std::cout << " ";
		i += 1;
	}

	int a = 0;
	while (a < sy) {
		if (a == 0) {
			cout << endl;
			a == 1;
		}
		cout << string(x, ' ');
		a++;
		cout << string(sx, '@') << endl;
	}
}

int main()
{
	setlocale(0, "");
	int x, y, sx, sy;

	printf("введите X: ");
	scanf_s("%d", &x);
	printf("введите Y: ");
	scanf_s("%d", &y);
	printf("введите SX: ");
	scanf_s("%d", &sx);
	printf("введите SY: ");
	scanf_s("%d", &sy);

	print_rect(x, y, sx, sy);
	return 400;
}