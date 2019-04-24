#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba(100);
	big_integer liczba3 = factorial(liczba);


	cout << liczba3 << endl;

	system ("pause");
	return 0;
}