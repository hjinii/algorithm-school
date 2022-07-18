#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream f_read("cube.inp");
ofstream f_write("cube.out");

void turn1(string &cube){ //1-6�� ���� ȸ��
	string tmp = cube;
	cube[1] = tmp[3];
	cube[2] = tmp[1];
	cube[3] = tmp[4];
	cube[4] = tmp[2];
}
void turn2(string &cube) { //2-5�� ���� ȸ��
	string tmp = cube;
	cube[0] = tmp[3];
	cube[2] = tmp[0];
	cube[3] = tmp[5];
	cube[5] = tmp[2];
}
void turn3(string &cube) { //3-4�� ���� ȸ��
	string tmp = cube;
	cube[0] = tmp[1];
	cube[1] = tmp[5];
	cube[4] = tmp[0];
	cube[5] = tmp[4];
}

bool compare(string cube1, string cube2) { //rgb���� ���� �� ť�� ȸ�� ��
	for (int i = 0; i < 4; i++) { //�� 4������ ȸ���ؾ� �ѹ��� ȸ���� ť�� �� ����
		turn1(cube2); //ȸ��
		if (cube1 == cube2)return true;

		for (int j = 0; j < 4; j++) {
			turn2(cube2); //ȸ��
			if (cube1 == cube2)return true;

			for (int k = 0; k < 4; k++) {
				turn3(cube2); //ȸ��
				if (cube1 == cube2)return true;
			}
		}
	}
	return false;
}

int main(void) {
	while (true) {
		string x;
		f_read >> x;

		string cube1, cube2;
		cube1 = x.substr(0, 6);
		cube2 = x.substr(6, 6);

		if (cube1 == cube2) { //���� ������ �� ������ �ƴ���
			int check = 0;
			char first = cube1[0];
			for (int i = 0; i < 6; i++) {
				if (first != cube1[i])
					check++;
			}
			if (check == 0) {
				f_write << "TRUE" << '\n';
				break;
			}
			else {
				f_write << "TRUE" << '\n';
			}
		}
		else {
			//r,g,b ���� count
			int r1 = 0, g1 = 0, b1 = 0, r2 = 0, g2 = 0, b2 = 0;
			for (int i = 0; i < 6; i++) {
				if (cube1[i] == 'r') r1++;
				else if (cube1[i] == 'g') g1++;
				else b1++;

				if (cube2[i] == 'r')r2++;
				else if (cube2[i] == 'g')g2++;
				else b2++;
			}

			if (r1 != r2 || g1 != g2 || b1 != b2) { //r,g,b ���� �ٸ��� FALSE
				f_write << "FALSE" << '\n';
			}
			else { //r,g,b ���� ������ ȸ�� �� �غ���
				bool com = compare(cube1, cube2);
				if (com) { //����
					f_write << "TRUE" << '\n';
				}
				else { //�ٸ�
					f_write << "FALSE" << '\n';
				}
			}
		}
	}
	f_read.close();
	f_write.close();
}