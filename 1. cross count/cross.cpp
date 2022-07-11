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
		f_read >> T; //����� ��

		for (int i = 0; i < T; i++) { //����� �� T����ŭ �ʱ�ȭ & ������ ���
			int n, result = 0;
			f_read >> n; //���� ����

			int *up = new int[n]; //�����ڿ�
			int *down = new int[n]; //�Ʒ����ڿ�

			//�����迭 �ʱ�ȭ
			for (int j = 0; j < n; j++) {
				f_read >> up[j];
			}
			for (int j = 0; j < n; j++) {
				f_read >> down[j];
			}

			int *order = new int[n]; //�Ʒ��ٿ� �ִ� ��ġ ���� �迭
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (up[x] == down[y]) {
						order[x] = y;
						break;
					}
				}
			}

			// ������ ���
			int j, k;
			for (j = 1; j < n; j++) {
				for (k = j - 1; k >= 0; k--) {
					if (order[k] > order[j]) { //�� ������ ��ġ�� �� ������ ��ġ���� ũ�ٸ�
						result++; //������ ����
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