#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream f_read("coin.inp");
ofstream f_write("coin.out");

void coin() {
	int m;
	f_read >> m;

	//2xm �迭
	vector<vector<int>> A(m, vector<int>(m));

	//A��� Set
	for (int i = 0; i < 2; i++) {
		int tmp;
		for (int j = 0; j < m; j++) {
			f_read >> tmp;
			A[i][j] = tmp;
		}
	}
	//0��� ��->�� ����
	for (int i = m - 2; i >= 0; i--) {
		A[0][i] += A[0][i + 1];
	}
	//1��� ��->�� ����
	for (int i = 1; i < m; i++) {
		A[1][i] += A[1][i - 1];
	}

	vector<int> B(m); //Bob�� ���� �� �ִ� ���� ��
	for (int i = 0; i < m; i++) {
		int one, two;
		if (i != 0 && i != m-1) {
			one = A[0][i + 1];
			two = A[1][i - 1];
			B[i] = max(one, two);
		}
		else if (i == 0) {
			B[i] = A[0][i + 1];
		}
		else {
			B[i] = A[1][i - 1];
		}
	}
	//B�迭 �� ���� ���� �� ����
	int MIN = B[0];
	for (int i = 1; i < m; i++) {
		MIN = min(B[i], MIN);
	}
	f_write << MIN << '\n';
}

int main(void) {
	int T;
	f_read >> T;

	for (int i = 0; i < T; i++) {
		coin();
	}
}