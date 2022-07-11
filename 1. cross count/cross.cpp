#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	ifstream f_read;
	ofstream f_write;
	f_read.open("cross.inp");
	f_write.open("cross.out");

	int T;
	if (f_read.is_open()) {
		f_read >> T; //경우의 수

		for (int i = 0; i < T; i++) { //경우의 수 T번만큼 초기화 & 교차점 계산
			int n, result = 0;
			f_read >> n; //숫자 개수

			int *up = new int[n]; //윗숫자열
			int *down = new int[n]; //아랫숫자열

			//동적배열 초기화
			for (int j = 0; j < n; j++) {
				f_read >> up[j];
			}
			for (int j = 0; j < n; j++) {
				f_read >> down[j];
			}

			int *order = new int[n]; //아랫줄에 있는 위치 저장 배열
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (up[x] == down[y]) {
						order[x] = y;
						break;
					}
				}
			}

			// 교차점 계산
			int j, k;
			for (j = 1; j < n; j++) {
				for (k = j - 1; k >= 0; k--) {
					if (order[k] > order[j]) { //앞 숫자의 위치가 뒤 숫자의 위치보다 크다면
						result++; //교차점 생김
					}
				}
			}
			f_write << "Case " << i + 1 << ": " << result << '\n';

			delete[]  up;
			delete[] down;
			delete[] order;
		}
		f_read.close();
		f_write.close();

		return 0;
	}
}