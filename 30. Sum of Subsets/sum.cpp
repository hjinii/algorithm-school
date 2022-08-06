#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("sum.inp");
ofstream f_write("sum.out");

int n, w;
int result = 0;

void sum_of_subsets(int i, int weight, int total, vector<int> &s) {
	//���� ��+���� ���� ���ϴ� ����ġ������ ũ��
	//���� ���� ����ġ���� ���ų� ���� ��+���� ��� ���� ���ϴ� ����ġ������ ��������
	//���ϴ� ����ġ���� ��������� ���� ��ġ�� �������.
	if (weight + total >= w && (weight == w || weight + s[i + 1] <= w)) {
		if (w == weight) {
			result++;
		}
		else {
			//��� �����ϴ� �� (1)
			sum_of_subsets(i + 1, weight + s[i + 1], total - s[i + 1], s);
			//��� ���� ���ϴ� �� (0)
			sum_of_subsets(i + 1, weight, total - s[i + 1], s);
		}
	}
}

void init() {	
	f_read >> n >> w;

	int total_sum = 0;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		int x;
		f_read >> x;
		s[i] = x;
		total_sum += x;
	}
	//�迭 �������� ����
	sort(s.rbegin(), s.rend());

	sum_of_subsets(-1, 0, total_sum, s);

	f_write << result << '\n';
	result = 0;
}


int main(void) {
	int T;
	f_read >> T;
	for (int i = 0; i < T; i++) {
		init();
	}
	return 0;
}