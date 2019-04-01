#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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
	friend big_integer add(const big_integer & a, const big_integer & b);
};