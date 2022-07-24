#include <iostream>
#include <fstream>
using namespace std;

ifstream f_read("addingways.inp");
ofstream f_write("addingways.out");

const int MOD = 1000000007;

void addingways(int n, int k) {
	int result[301][301] = { 0 };

	//n을 1개의 자연수합으로 만드는 방법 == 1가지
	//n을 n개의 자연수합으로 만드는 방법 == 1가지
	for (int i = 1; i <= n; i++) { 
		result[i][1] = 1;
		for (int j = 1; j <= i; j++)
			if (i == j)
				result[i][j] = 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i != j && j != 1) {
				int sum = 0;
				for (int tmp = 1; tmp <= j; tmp++) {
					if (tmp > (i - j)) {
						break;
					}
					sum = ((result[i - j][tmp] % MOD) + (sum % MOD)) % MOD;
				}
				result[i][j] = sum % MOD;
			}
		}
	}
	f_write << result[n][k] << '\n';
}

int main(void) {
	int n, k;
	while (true) {
		f_read >> n >> k;
		if (n == 0 && k == 0) { //END
			break;
		}
		else {
			addingways(n, k);
		}
	}
	return 0;
}