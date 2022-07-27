#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

ifstream f_read("airconditiner.inp");
ofstream f_write("airconditiner.out");

long long n, k;

void airconditioner() {
	f_read >> n;
	f_read >> k;

	vector<long long> N(n);
	vector<long long> A(k);
	vector<long long> T(k);

	long long tmp, i, j;
	for (i = 0; i < k; i++) {
		f_read >> tmp;
		A[i] = tmp;
	}
	for (i = 0; i < k; i++) {
		f_read >> tmp;
		T[i] = tmp;
	}
	
	for (i = 0; i < n; i++) {
		long long MIN = 1000000000;
		for (j = 0; j < k; j++) {
			N[i] = min(T[j] + abs(A[j] - (i + 1)) , MIN);
			MIN = N[i];
		}
		f_write << N[i] << ' ';
	}
	f_write << '\n';
}

int main(void) {
	int T;
	f_read >> T;

	for (int i = 0; i < T; i++) {
		airconditioner();
	}
}