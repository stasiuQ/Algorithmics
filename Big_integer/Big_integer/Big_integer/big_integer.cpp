#include "big_integer.h"

big_integer::big_integer(string string_number)
{
	this->string_number = string_number;
	this->array_size = string_number.size();
	number.push_back(0);
	if (string_number[0] == '-')
		number[0] = 1;    // first byte states for the sign
	for (int i = 1; i < string_number.size(); i++) {
		number.push_back(static_cast<int>(string_number[i]));
		if (number[i] > 9) throw "This is not a decimal number";
	}
}

big_integer::big_integer(int integer_number)
{
	string str_number = to_string(integer_number);
	big_integer::big_integer(str_number);
}


big_integer::big_integer():string_number("0"), array_size(0) {}

big_integer::~big_integer()
{
}

big_integer & big_integer::operator=(const big_integer & b)
{
	this->string_number = b.string_number;
	this->array_size = b.array_size;
	this->number = b.number;
}

big_integer operator+(const big_integer & a, const big_integer & b)
{
	string temp_number;

	return big_integer();
}

big_integer operator-(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

big_integer operator*(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

big_integer operator/(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

ostream & operator<<(ostream & out, const big_integer & a)
{
	out << a.string_number;
	return out;
}
