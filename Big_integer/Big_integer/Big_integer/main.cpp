#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("-19999");
	big_integer liczba2("987");
	big_integer liczba3 = liczba * liczba2;


	cout << liczba3 << endl;

	system ("pause");
	return 0;
}