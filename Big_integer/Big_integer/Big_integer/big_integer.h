#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

class big_integer {
protected:
	string string_number;
	unsigned int array_size;
	vector<int> number;

public:
	big_integer(string string_number);
	big_integer(int integer_number);
	big_integer(); // default constructor
	~big_integer();

	big_integer& operator = (const big_integer &b);
	friend big_integer operator + (const big_integer &a, const big_integer &b);
	friend big_integer operator - (const big_integer &a, const big_integer &b);
	friend big_integer operator * (const big_integer &a, const big_integer &b);
	friend big_integer operator / (const big_integer &a, const big_integer &b);
	friend ostream& operator << (ostream& out, const big_integer &a);
	friend bool operator <(const big_integer & a, const big_integer & b);
	friend bool operator >(const big_integer & a, const big_integer & b);
	friend bool operator ==(const big_integer & a, const big_integer & b);
	friend big_integer pow(const big_integer & a, unsigned int i);
	friend big_integer factorial(const big_integer &a);

	friend big_integer add(const big_integer & a, const big_integer & b);
	friend big_integer substract(const big_integer & a, const big_integer & b);
	friend big_integer karatsuba(const big_integer & a, const big_integer & b);

};