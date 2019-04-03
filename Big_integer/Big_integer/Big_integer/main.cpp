#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("-5");
	big_integer liczba3 = pow(liczba,5);


	cout << liczba3 << endl;

	system ("pause");
	return 0;
}