#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("sum.inp");
ofstream f_write("sum.out");

int n, w;
int result = 0;

void sum_of_subsets(int i, int weight, int total, vector<int> &s) {
	//현재 합+남은 합이 구하는 가중치값보다 크고
	//현재 합이 가중치값과 같거나 현재 합+다음 노드 값이 구하는 가중치값보다 작을때만
	//구하는 가중치값에 가까워지기 위해 가치를 뻗어나간다.
	if (weight + total >= w && (weight == w || weight + s[i + 1] <= w)) {
		if (w == weight) {
			result++;
		}
		else {
			//노드 선택하는 쪽 (1)
			sum_of_subsets(i + 1, weight + s[i + 1], total - s[i + 1], s);
			//노드 선택 안하는 쪽 (0)
			sum_of_subsets(i + 1, weight, total - s[i + 1], s);
		}
	}
}

void init() {	
	f_read >> n >> w;

	int total_sum = 0;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		int x;
		f_read >> x;
		s[i] = x;
		total_sum += x;
	}
	//배열 내림차순 정렬
	sort(s.rbegin(), s.rend());

	sum_of_subsets(-1, 0, total_sum, s);

	f_write << result << '\n';
	result = 0;
}


int main(void) {
	int T;
	f_read >> T;
	for (int i = 0; i < T; i++) {
		init();
	}
	return 0;
}