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
	vector<int> log(n); //값 입력받는 배열

	for (int i = 0; i < n; i++) {
		int L;
		f_read >> L;
		log[i] = L;
	}
	//배열 오름차순 정렬
	sort(log.begin(), log.end());
	
	//작은수부터 오른쪽왼쪽 번갈아 배열에 넣어 그 차를 구하는 원리이므로
	//따로 배열에 넣지않고
	//바로 두칸씩 뛰면서 차를 구하고 가장 큰 값 출력
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