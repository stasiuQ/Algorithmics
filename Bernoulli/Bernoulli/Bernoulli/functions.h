#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

bool bernoulli(double probability);

int X_geo(double probability);

vector<double> geometric_dist(int N, double probability);

vector<double> probe_1k(int n, int no_probes);

vector<double> probe_const(int n, int no_probes, double probability);

void print_vector(fstream& file, vector<double>& tab);
