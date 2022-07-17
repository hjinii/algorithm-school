#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main(void) {
	ifstream f_read;
	ofstream f_write;
	f_read.open("sequence.inp");
	f_write.open("sequence.out");

	int n, tmp;
	f_read >> n;

	vector<int> s, c, x;
	x.resize(n); //������ �� ������ �迭

	for (int i = 0; i < n; i++) {
		f_read >> tmp;
		s.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		f_read >> tmp;
		c.push_back(tmp);
	}

	sort(s.begin(), s.end()); //S �������� ����

	for (int i = n - 1; i >= 0; i--) { //X, C �迭 �ڿ��� ����
		x[i] = s[c[i]]; //S�� C[i]�ε��� X[i]�� ����
		s.erase(s.begin() + c[i]); //X[i]�� ����� S ��� ����� -> S ��迭
	}

	for (int i = 0; i < n; i++) {
		f_write << x[i] << '\n';
	}

	f_read.close();
	f_write.close();

	return 0;
}