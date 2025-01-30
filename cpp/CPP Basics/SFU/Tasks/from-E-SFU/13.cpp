#include  <iostream>
using namespace std;

double ai(int i) {
	double a,s = 0;
	for (int j = 1; j <= i; j++) {
		a = j + 1;
		s += j / a;
	}
	
	return s;
}




int main() {
	int n;
	scanf_s("%d", &n);
	cout << ai(n);
		
		
}