#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("jump.inp");
ofstream f_write("jump.out");

void jumping() {
	int n;
	f_read >> n;
	vector<int> log(n); //�� �Է¹޴� �迭

	for (int i = 0; i < n; i++) {
		int L;
		f_read >> L;
		log[i] = L;
	}
	//�迭 �������� ����
	sort(log.begin(), log.end());
	
	//���������� �����ʿ��� ������ �迭�� �־� �� ���� ���ϴ� �����̹Ƿ�
	//���� �迭�� �����ʰ�
	//�ٷ� ��ĭ�� �ٸ鼭 ���� ���ϰ� ���� ū �� ���
	int result = 0;
	for (int i = 2; i < n; i++) {
		int cmp = log[i] - log[i - 2];
		result = max(result, cmp);
	}
	f_write << result << '\n';
}


int main(void) {
	int T;
	f_read >> T;
	for (int i = 0; i < T; i++) {
		jumping();
	}
}