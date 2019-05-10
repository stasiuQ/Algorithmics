#include "functions.h"

using namespace std;

bool bernoulli(double probability)
{
	double rand_temp; // random number from 0 to 1 with homogenious distribution
	rand_temp = static_cast<double>(rand()) / RAND_MAX;
	if (rand_temp <= probability)
		return true;
	else
		return false;
}

int X_geo(double probability)
{
	int no_probes = 0;
	bool flag = false;
	while (flag == false) {
		flag = bernoulli(probability);
		no_probes++;
	}
	return no_probes;
}

vector <double> geometric_dist(int N, double probability)
{
	vector<int> temp (N);
	int temp_max = 0;

	for (int i = 0; i < N; i++) {
		temp[i] = X_geo(probability);
		if (temp[i] > temp_max)
			temp_max = temp[i];
	}

	vector<double> histogram(temp_max + 1);
	for (int i = 1; i <= temp_max; i++) {
		int counter = 0;
		for (int q = 0; q < temp.size(); q++) {   // looking for a particular k in temp vector
			if (temp[q] == i)
				counter++;
		}
		histogram[i] = static_cast<double>(counter) / N;
	}

	return histogram;
}

vector<double> probe_1k(int n, int no_probes)
{
	vector<int> temp(no_probes);
	for (int q = 0; q < no_probes; q++) {

		int counter = 1;
		for (int i = 2; i <= n; i++) {
			double probability = 1 / static_cast<double>(i);
			double rand_temp = static_cast<double>(rand()) / RAND_MAX;
			if (rand_temp <= probability)
				counter = i;
		}
		temp[q] = counter;
	}

	vector<double> histogram(n + 1);
	for (int i = 1; i <= n; i++) {
		int counter = 0;
		for (int q = 0; q < temp.size(); q++) {   // looking for a particular k in temp vector
			if (temp[q] == i)
				counter++;
		}
		histogram[i] = static_cast<double>(counter)/no_probes;
	}
	return histogram;
}

vector<double> probe_const(int n, int no_probes, double probability)
{
	vector<int> temp(no_probes);
	for (int q = 0; q < no_probes; q++) {

		int counter = 1;
		for (int i = 2; i <= n; i++) {
			double rand_temp = static_cast<double>(rand()) / RAND_MAX;
			if (rand_temp <= probability)
				counter = i;
		}
		temp[q] = counter;
	}

	vector<double> histogram(n + 1);
	for (int i = 1; i <= n; i++) {
		int counter = 0;
		for (int q = 0; q < temp.size(); q++) {   // looking for a particular k in temp vector
			if (temp[q] == i)
				counter++;
		}
		histogram[i] = static_cast<double>(counter)/no_probes;
	}
	return histogram;
}

void print_vector(fstream& file, vector<double>& tab)
{
	for (int i = 1; i < tab.size(); i++) {
		file << i << "	" << tab[i] << endl;
	}
}
