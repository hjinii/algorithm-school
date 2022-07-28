#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream f_read("cube.inp");
ofstream f_write("cube.out");

int input_w, input_l, input_h;
int cube[201][201][201];

void cube_cut() {
	for (int W = 1; W < 201; W++) {
		for (int L = 1; L < 201; L++) {
			for (int H = 1; H < 201; H++) {
				if (cube[W][L][H] == 0) {
					//가로or세로or높이가 1인 경우
					if (W == 1 || L == 1 || H == 1)
						cube[W][L][H] = W * L * H;
					//두 길이가 나머지 한 길이의 배수인 경우
					else if (W%H == 0 && L%H == 0)
						cube[W][L][H] = (W / H) * (L / H);
					else if(W%L == 0 && H%L == 0)
						cube[W][L][H] = (W / L) * (H / L);
					else if (L%W == 0 && H%W == 0)
						cube[W][L][H] = (L / W) * (H / W);
					//그 외
					else {
						cube[W][L][H] = 1000000000;
						//가로 W 기준 자르기
						for (int i = 1; i <= W / 2; i++) {
							cube[W][L][H] = min(cube[W][L][H], cube[i][L][H] + cube[W - i][L][H]);
						}
						//세로 L 기준 자르기
						for (int i = 1; i <= L / 2; i++) {
							cube[W][L][H] = min(cube[W][L][H], cube[W][i][H] + cube[W][L - i][H]);
						}
						//높이 H 기준 자르기
						for (int i = 1; i <= H / 2; i++) {
							cube[W][L][H] = min(cube[W][L][H], cube[W][L][i] + cube[W][L][H - i]);
						}
					}

					//돌린 직육면체와 값 같음
					cube[W][H][L] = cube[W][L][H];
					cube[L][W][H] = cube[W][L][H];
					cube[L][H][W] = cube[W][L][H];
					cube[H][W][L] = cube[W][L][H];
					cube[H][L][W] = cube[W][L][H];
				}
			}
		}
	}
}

int main(void) {
	int T;
	f_read >> T;

	cube_cut();
	for (int i = 0; i < T; i++) {
		f_read >> input_w >> input_l >> input_h;
		f_write << cube[input_w][input_l][input_h] << '\n';
	}
}