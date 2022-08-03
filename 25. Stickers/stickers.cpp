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

	//2행n열 2차원 배열
	vector<vector<int>> arr(2, vector<int>(n));

	int x;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			f_read >> x;
			arr[i][j] = x;
		}
	}

	//2열이상일때만 계산
	if (n != 1) {
		arr[0][1] += arr[1][0];
		arr[1][1] += arr[0][0];
	}
	
	//1칸뒤 선택하는 경우와 2칸뒤 선택하는 경우 중 큰값 선택
	//기존값에 누적합
	for (int i = 2; i < n; i++) {
		arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
		arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
	}

	//0행,1행의 마지막 열 두 값중 큰값 출력 
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