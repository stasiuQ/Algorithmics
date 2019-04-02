#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("500");
	big_integer liczba2("500");
	//big_integer liczba3 = karatsuba(liczba2, liczba);
	big_integer liczba3 = big_integer(5) + big_integer(5);

	cout << liczba3 << endl;

	system ("pause");
	return 0;
}