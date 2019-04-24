#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;


bool none_empty(int* baskets, int N) {
	bool flag = true;
	int i = 0;
	while (i < N && flag == true) {
		if (baskets[i] == 0) {
			flag = false;
		}
		i++;
	}
	return flag;
}

int no_empty(int N) {
	int* baskets = new int[N];
	for (int q = 0; q < N; q++) {
		baskets[q] = 0;
	}

	int element = 0;
	int i = 0;   // iterator
	while (none_empty(baskets, N) == false) {   // filling baskets with balls
		element = floor((static_cast<double>(rand()) / RAND_MAX)*N);
		if (element == N)
			element--;
		baskets[element]++;
		i++;
	}
	delete[] baskets;
	return i;
}

int two_balls(int N) {
	int* baskets = new int[N];
	for (int q = 0; q < N; q++) {
		baskets[q] = 0;
	}

	bool flag = false;
	int element = 0;
	int i = 0;   // iterator
	while (flag == false) {   // filling baskets with balls
		element = floor((static_cast<double>(rand()) / RAND_MAX)*N);
		if (element == N)
			element--;
		baskets[element]++;
		if (baskets[element] == 2)
			flag = true;
		i++;
	}
	delete[] baskets;
	return i;
}

double average(vector<int>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	return (static_cast<double>(sum) / vec.size());
}

int main() {
	fstream file_empty;
	fstream file_two;
	file_empty.open("non_empty.txt", ios::trunc);
	file_two.open("two_balls.txt", ios::trunc);

	const int N_max = 100;
	const int no_probes = 100000;
	srand(time(NULL));
	

	for (int i = 10; i <= N_max; i++) {
		vector<int> empty;
		vector<int> two;
		for (int q = 0; q < no_probes; q++) {
			empty.push_back(no_empty(i));
			two.push_back(two_balls(i));
		}
		file_empty << i << "   " << average(empty) << endl;
		file_two << i << "   " << average(two) << endl;
	}
	

	file_empty.close();
	file_two.close();
	return 0;
}