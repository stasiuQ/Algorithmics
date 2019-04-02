#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("123456789");
	big_integer liczba2("123456789");
	big_integer liczba3 = liczba2 - liczba;

	cout << liczba3 << endl;

	system ("pause");
	return 0;
}