#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("10");
	big_integer liczba3 = !liczba;


	cout << liczba3 << endl;

	system ("pause");
	return 0;
}