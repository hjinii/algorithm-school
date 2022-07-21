#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

ifstream f_read("watertank.inp");
ofstream f_write("watertank.out");

int N, M, H; //세로, 가로, 높이
int hole[1003][1003][4];
int depth[1003][1003];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

typedef struct tank{
	int x, y, h;
};

class compare {
public:
	bool operator()(tank &t1, tank &t2) {
		if (t1.h > t2.h) return true;\
		else return false;
	}
};

void input() {
	f_read >> N >> M >> H;

	int tmp;
	for (int i = 1; i  <= N+1; i++) { //상하 구멍
		for (int j = 1; j <= M; j++) {
			f_read >> tmp;
			hole[i - 1][j][2] = tmp;
			hole[i][j][0] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) { //좌우 구멍
		for (int j = 1; j <= M + 1; j++) {
			f_read >> tmp;
			hole[i][j - 1][1] = tmp;
			hole[i][j][3] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) { //구멍 X 가정 -> 물 가득 채움
		for (int j = 1; j <= M; j++) {
			depth[i][j] = H;
		}
	}
}

void BFS() {
	input(); //구멍 입력받기

	int next_x, next_y, next_h;
	tank current;
	//우선순위 큐 생성
	priority_queue<tank, vector<tank>, compare>pq;

	//바깥 구멍 높이 기준으로 설정
	for (int i = 0; i <= M + 1; i++) { //상하
		if (hole[0][i][2] != -1) { //구멍이 있다면
			pq.push({ 1,i,hole[0][i][2] });
			depth[1][i] = hole[0][i][2];
		}
		if (hole[N + 1][i][0] != -1) {
			pq.push({ N,i,hole[N + 1][i][0] });
			depth[N][i] = hole[N + 1][i][0];
		}
	}
	for (int i = 0; i <= N+1; i++) { //좌우
		if (hole[i][0][1] != -1) {
			pq.push({ i,1,hole[i][0][1] });
			depth[i][1] = hole[i][0][1];
		}
		if (hole[i][M + 1][3] != -1) {
			pq.push({ i,M,hole[i][M + 1][3] });
			depth[i][M] = hole[i][M + 1][3];
		}
	}

	while (pq.size()) {
		current = pq.top();
		pq.pop();

		// depth가 갱신되지 않았다면
		if (current.h == depth[current.x][current.y]) {
			for (int i = 0; i < 4; i++) {
				if (hole[current.x][current.y][i] != -1) {
					if (i == 0) {                
						next_x = current.x + -1;
						next_y = current.y;
					}
					else if (i == 1) {          
						next_x = current.x;
						next_y = current.y + 1;
					}
					else if (i == 2) {          
						next_x = current.x + 1;
						next_y = current.y;
					}
					else {                      
						next_x = current.x;
						next_y = current.y + -1;
					}
					//범위 벗어나지 않았을 시
					if (!(next_x < 1 || next_y < 1 || next_x > N || next_y > M)) {
						next_h = max(min(hole[current.x][current.y][i], depth[next_x][next_y]), depth[current.x][current.y]);
						if (depth[next_x][next_y] > next_h) {
							depth[next_x][next_y] = next_h;
							pq.push({ next_x,next_y,next_h });
						}
					}
				}
			}
		}
	}


	int answer = 0;
	for (int i = 1; i <= N; i++) { //물 탱크 총 부피 계산
		for (int j = 1; j <= M; j++) {
			answer += depth[i][j];
		}
	}
	f_write << answer << "\n";
}

int main(void) {
	int T;
	f_read >> T;

	for (int i = 0; i < T; i++) {
		BFS();
	}
}