#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double num_people, num_seats, num_buses, num_free_seats;
	setlocale(0, "");

	printf("Введите количество людей \n");
	scanf_s("%lf",&num_people);
	printf("Введите количество мест в автобусе \n");
	scanf_s("%lf", &num_seats);

	num_buses = ceil(num_people / num_seats);
	num_free_seats = abs(num_people - (num_seats * num_buses));

	printf("автобусов надо - %lf", num_buses);
	printf("останется свободных мест -  %lf", num_free_seats);
	return 0;
}