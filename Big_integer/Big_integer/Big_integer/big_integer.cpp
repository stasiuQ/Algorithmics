#include "big_integer.h"

big_integer::big_integer(string string_number)
{
	this->string_number = string_number;
	this->array_size = string_number.size();
	number.push_back(0);
	int j = 0; // iterator in string
	if (string_number[0] == '-') {
		number[0] = 1;    // first byte states for the sign
		j = 1; // switching position of iterator
	}
	for (int i = (string_number.size()-1); i >=j ; i--) {
		number.push_back(static_cast<int>(string_number[i])-48); // converting ASCII to integer
	}
}

big_integer::big_integer(int integer_number)
{
	string str_number = to_string(integer_number);
	this->string_number = str_number;
	this->array_size = str_number.size();
	number.push_back(0);
	int j = 0; // iterator
	if (str_number[0] == '-') {
		number[0] = 1;    // first byte states for the sign
		j = 1; // switching position of iterator
	}
	for (int i = (str_number.size() -1); i >= j; i--) {
		number.push_back(static_cast<int>(str_number[i]) - 48); // converting ASCII to integer
	}
}


big_integer::big_integer():string_number("0"), array_size(0) {}

big_integer::~big_integer()
{
}

big_integer & big_integer::operator =(const big_integer & b)
{
	this->string_number = b.string_number;
	this->array_size = b.array_size;
	this->number = b.number;
	return *this;
}

big_integer operator +(const big_integer & a, const big_integer & b)
{
	big_integer temp;
	if ((a.number[0] == 0) && (b.number[0] == 0)) {
		temp = add(a, b);
	}
	else if ((a.number[0] == 1) && (b.number[0] == 1)) {
		temp = add(a, b);
		temp.number[0] = 1;
		temp.string_number.insert(0, "-");
		temp.array_size++;
	}
	else if ((a.number[0] == 0) && (b.number[0] == 1)) {
		if (a > b || a == b) {
			temp = substract(a, b);
		}
		else{
			temp = substract(b, a);
			temp.number[0] = 1;
			temp.string_number.insert(0, "-");
			temp.array_size++;
		}
	}
	else if ((a.number[0] == 1) && (b.number[0] == 0)){
		if (a < b || a == b) {
			temp = substract(b, a);
		}
		else {
			temp = substract(a, b);
			temp.number[0] = 1;
			temp.string_number.insert(0, "-");
			temp.array_size++;
		}
	}
	return temp;
}

big_integer operator -(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

big_integer operator *(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

big_integer operator /(const big_integer & a, const big_integer & b)
{
	return big_integer();
}

ostream & operator <<(ostream & out, const big_integer & a)
{
	out << a.string_number;
	return out;
}



bool operator <(const big_integer & a, const big_integer & b) // just comparing modules
{
	if (a.number.size() > b.number.size())
		return false;
	else if (a.number.size() < b.number.size())
		return true;
	else {
		for (int i = (a.number.size() - 1); i >= 1; i--) {
			if (a.number[i] > b.number[i])
				return false;
			else if (a.number[i] < b.number[i])
				return true;
		}
		return false;
	}
}

bool operator >(const big_integer & a, const big_integer & b)
{
	if (a.number.size() < b.number.size())
		return false;
	else if (a.number.size() > b.number.size())
		return true;
	else {
		for (int i = (a.number.size() - 1); i >= 1; i--) {
			if (a.number[i] < b.number[i])
				return false;
			else if (a.number[i] > b.number[i])
				return true;
		}
		return false;
	}
}

bool operator ==(const big_integer & a, const big_integer & b)
{
	if (a.number[0] != b.number[0])
		return false;
	else if (a.number.size() != b.number.size())
		return false;
	else {
		for (int i = (a.number.size() - 1); i >= 1; i--) {
			if (a.number[i] != b.number[i])
				return false;
		}
	}
	return true;
}


big_integer add(const big_integer & a, const big_integer & b) {
	big_integer temp;
	int decimal_shift = 0;
	int i = 1;
	temp.number.push_back(0);
	while (i <= min(a.array_size, b.array_size)) {
		temp.number.push_back((a.number[i] + b.number[i] + decimal_shift) % 10);
		if ((a.number[i] + b.number[i] + decimal_shift) <= 9)
			decimal_shift = 0;
		else
			decimal_shift = 1;
		i++;
	}
	if (a.array_size >= b.array_size) {
		while (i <= a.array_size) {
			temp.number.push_back((a.number[i] + decimal_shift) % 10);
			if ((a.number[i] + decimal_shift) <= 9)
				decimal_shift = 0;
			else
				decimal_shift = 1;
			i++;
		}
		if (decimal_shift == 1)
			temp.number.push_back(1);
	}
	else {
		while (i <= b.array_size) {
			temp.number.push_back((b.number[i] + decimal_shift) % 10);
			if ((b.number[i] + decimal_shift) <= 9)
				decimal_shift = 0;
			else
				decimal_shift = 1;
			i++;
		}
		if (decimal_shift = 1)
			temp.number.push_back(1);
	}
	temp.array_size = temp.number.size() - 1; // because, for now, temp is always possitive, be like temp :)
	temp.string_number.clear();
	for (int q = temp.array_size; q >= 1; q--) {
		char c = '0' + temp.number[q];
		temp.string_number.push_back(c);
	}

	return temp;
}

big_integer substract(const big_integer & a, const big_integer & b) // substracting 2 positive sorted integers
{
	vector<int> a_number = a.number;
	vector<int> b_number = b.number;
	vector<int> temp_number;
	string temp_string;

	if (a > b || a == b) {
		temp_number.push_back(0);
		int i = b_number.size();
		for (i; i <= (a_number.size()-1); i++) {
			b_number.push_back(0);
		}
		for (int q = 1; q <= (a_number.size()-1); q++) {
			if (a_number[q] - b_number[q] < 0) {
				a_number[q + 1]--;
				temp_number.push_back(a_number[q] - b_number[q] + 10);
			}
			else
				temp_number.push_back(a_number[q] - b_number[q]);
		}
		temp_string.clear();
		for (int q = (temp_number.size()-1); q >= 1; q--) {
			char c = '0' + temp_number[q];
			temp_string.push_back(c);
		}
	}
	else
		throw "Switch integers";
	return big_integer(temp_string);
}
