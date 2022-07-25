#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f_read("jump.inp");
ofstream f_write("jump.out");

void jump() {
	long long n;
	f_read >> n;

	vector<long long> a;
	long long tmp;
	for (int i = 0; i < n; i++) {
		f_read >> tmp;
		a.push_back(tmp);
	}
	
	long long score = 0, score_tmp = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (true) {
			if (j > n)
				break;
			score_tmp += a[j - 1];
			j += a[j - 1];			
		}
		if (score_tmp > score) {
			score = score_tmp;
		}
		score_tmp = 0;
	}

	f_write << score << '\n';
}

int main(void) {
	int T;
	f_read >> T;

	for (int i = 0; i < T; i++) {
		jump();
	}

	return 0;
}