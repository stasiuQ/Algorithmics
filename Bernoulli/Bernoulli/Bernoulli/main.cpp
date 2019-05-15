#include "functions.h"
# include <ctime>

using namespace std;

int main() {
	fstream geo_distr;
	fstream probe_A;
	fstream probe_B;

	srand(time(NULL));

	geo_distr.open("geo_distr.txt", ios::out);
	probe_A.open("probe_A.txt", ios::out);
	probe_B.open("probe_B.txt", ios::out);

	const int N = 1000000;   // number of uncorrelated experiments
	const double P = 0.2;  // probability of single Bernoulli try

	vector<double> histogram1 = geometric_dist(N, P);
	print_vector(geo_distr, histogram1);

	const int n = 100; // lenght of a data stream

	vector<double> histogram2 = probe_1k(n, N);
	vector<double> histogram3 = probe_const(n, N, P);
	print_vector(probe_A, histogram2);
	print_vector(probe_B, histogram3);

	geo_distr.close();
	probe_A.close();
	probe_B.close();

	system("PAUSE");

	return 0;
}