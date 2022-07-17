#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main(void) {
	ifstream f_read;
	ofstream f_write;
	f_read.open("sequence.inp");
	f_write.open("sequence.out");

	int n, tmp;
	f_read >> n;

	vector<int> s, c, x;
	x.resize(n); //정렬한 값 저장할 배열

	for (int i = 0; i < n; i++) {
		f_read >> tmp;
		s.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		f_read >> tmp;
		c.push_back(tmp);
	}

	sort(s.begin(), s.end()); //S 오름차순 정렬

	for (int i = n - 1; i >= 0; i--) { //X, C 배열 뒤에서 부터
		x[i] = s[c[i]]; //S의 C[i]인덱스 X[i]에 저장
		s.erase(s.begin() + c[i]); //X[i]에 저장된 S 요소 지우기 -> S 재배열
	}

	for (int i = 0; i < n; i++) {
		f_write << x[i] << '\n';
	}

	f_read.close();
	f_write.close();

	return 0;
}