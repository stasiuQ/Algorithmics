#include "big_integer.h"
#include <iostream>

using namespace std;

int main() {
	big_integer liczba("1982");
	big_integer liczba2("18");
	big_integer liczba3 = add(liczba, liczba2);

	cout << liczba3 << endl;

	system ("pause");
	return 0;
}