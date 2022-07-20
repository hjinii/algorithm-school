#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f_read("fibonacci.inp");
ofstream f_write("fibonacci.out");

vector<vector<long long> > cal(vector<vector<long long> > &matrix1, vector<vector<long long> > &matrix2, long long M) {
	long long x = matrix1.size();
	vector<vector<long long> > result(x, vector<long long>(x));

	for (int i = 0; i < x; i++) { //��İ� ���
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < x; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] %= M; //���ڰ� �ʹ� Ŀ���� �Ǵ� ���� ����
		}
	}
	return result;
}

long long fib(long long n, long long M) {
	vector<vector<long long> > answer = { {1, 0}, 
										  {0, 1} };
	vector<vector<long long> > matrix = { {1, 1},
									      {1, 0} };

	//�������� �̿��� �Ǻ���ġ ����
	while (n > 0) {
		if (n % 2 == 1) { //n Ȧ���϶�
			answer = cal(answer, matrix, M); //��� �ѹ� �� ������
		}
		matrix = cal(matrix, matrix, M);
		n /= 2; //�������� ã�ư�
	}
	return answer[0][1];
}

int main(void) {
	int T;
	f_read >> T;

	long long a, b, c, d, M;
	for (int i = 0; i < T; i++) {
		f_read >> a >> b >> c >> d >> M;
		a = fib(a, M);
		b = fib(b, M);
		c = fib(c, M);
		d = fib(d, M);

		f_write << ((a * b) + (c * d)) % M << "\n";
	}
	return 0;
}