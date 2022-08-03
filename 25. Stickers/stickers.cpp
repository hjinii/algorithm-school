#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("stickers.inp");
ofstream f_write("stickers.out");

void stickers() {
	int n;
	f_read >> n;

	//2��n�� 2���� �迭
	vector<vector<int>> arr(2, vector<int>(n));

	int x;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			f_read >> x;
			arr[i][j] = x;
		}
	}

	//2���̻��϶��� ���
	if (n != 1) {
		arr[0][1] += arr[1][0];
		arr[1][1] += arr[0][0];
	}
	
	//1ĭ�� �����ϴ� ���� 2ĭ�� �����ϴ� ��� �� ū�� ����
	//�������� ������
	for (int i = 2; i < n; i++) {
		arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
		arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
	}

	//0��,1���� ������ �� �� ���� ū�� ��� 
	f_write << max(arr[0][n - 1], arr[1][n - 1]) << '\n';
}

int main(void) {
	int T;
	f_read >> T;
	for (int i = 0; i < T; i++) {
		stickers();
	}
	return 0;
}