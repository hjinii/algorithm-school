#include <iostream>
#include <fstream>
using namespace std;

void cal() {
	ifstream f_read;
	ofstream f_write;
	f_read.open("bowling.inp");
	f_write.open("bowling.out");

	int T;
	if (f_read.is_open()) {
		f_read >> T; //�׽�Ʈ ���� (<=10)

		for (int k = 0; k < T; k++) {
			int a;
			double set = 0;
			int count = 21; //�Էµ� ���� ����
			int arr[21];

			for (int i = 0; i < count; i++) { //�迭�� ���� ����
				if (set < 9) { //9set����
					f_read >> arr[i];
					if (arr[i] == 10 && (set - 0.5 ) != (int)set) { //��Ʈ����ũ�� ��
						count--; //�迭 ���� -1
						set++;
					}
					else { //��Ʈ����ũ X, ����� O (0 10�� ����)
						set += 0.5;
					}
				}
				else { //10set�� ��
					f_read >> arr[i];
					f_read >> arr[i + 1];
					if (arr[i] != 10 && (arr[i] + arr[i + 1]) != 10) { //��Ʈ����ũ X and ����� X -> 10set ��ȸ 2�� 
						count--; //�迭 ���� -1
						break;
					}
					else { //��Ʈ����ũ O or ����� O -< 10set ��ȸ 3��
						f_read >> arr[i + 2];
						break;
					}
				}
			}
			

			//���� ���
			set = 0;
			int result = 0, sum;
			for (int i = 0; i < count; i++) {
				if (arr[i] != 10 && set < 9) { //��Ʈ����ũ X
					sum = arr[i] + arr[i + 1];
					if (sum != 10) { //����� ó�� X
						result += sum;
						i++;
						set++;
					}
					else { //����� ó�� O
						result += 10;
						result += arr[i + 2]; //���� �������� �ջ�
						i++;
						set++;
					}
				}
				else if (arr[i] == 10 && set < 9) { //��Ʈ����ũ O
					result += 10;
					result += arr[i + 1];
					result += arr[i + 2];
					set++;
				}
				else { //������ 10set ���
					result += arr[i];
				}
			}
			f_write << result << '\n';
			
		}
	}
	f_read.close();
	f_write.close();
}

int main(void) {
	cal();
}