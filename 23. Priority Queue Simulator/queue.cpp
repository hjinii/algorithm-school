#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("queue.inp");
ofstream f_write("queue.out");


void tree_sort(vector<int>& tree) {
	//child를 parent와 비교하면서 정렬
	int i;
	i = tree.size() - 1;
	while (i > 0) {
		if (i % 2 != 0) { //홀수
			if (tree[i] <= tree[(i-1) / 2]) break;
			else {
				int tmp = tree[i];
				tree[i] = tree[(i-1) / 2];
				tree[(i-1) / 2] = tmp;

				i = (i-1) / 2;
			}
		}
		else { //짝수
			if (tree[i] <= tree[(i - 2) / 2]) break;
			else {
				int tmp = tree[i];
				tree[i] = tree[(i - 2) / 2];
				tree[(i - 2) / 2] = tmp;

				i = (i - 2) / 2;
			}
		}
	}
}

void adjust(vector<int>& tree) {
	int i = 0;
	while (true) {
		//자식없는 마지막 노드이면 종료
		if ((i * 2 + 1) > (tree.size()-1)  && (i * 2 + 2) > (tree.size()-1)) break;
		else {
			//우측 자식 없을때
			if ((i * 2 + 2) > (tree.size() - 1)) {
				int tmp = tree[i];
				tree[i] = tree[i * 2 + 1];
				tree[i * 2 + 1] = tmp;
				break;
			}
			//좌우측 자식 모두 있을때
			else {
				int bigger = max(tree[i * 2 + 1], tree[i * 2 + 2]);
				if (tree[i] >= bigger) break;
				else {
					if (tree[i * 2 + 1] >= tree[i * 2 + 2]) {
						int tmp = tree[i];
						tree[i] = tree[i * 2 + 1];
						tree[i * 2 + 1] = tmp;

						i = i * 2 + 1;
					}
					else {
						int tmp = tree[i];
						tree[i] = tree[i * 2 + 2];
						tree[i * 2 + 2] = tmp;

						i = i * 2 + 2;
					}
				}
			}
		}
	}
}

int main(void) {
	string input;
	vector<int> tree;

	while (true) {
		f_read >> input;
		if (input == "q") break;
		//d : root삭제, 마지막 키값 루트에 올린후 adjust알고리즘
		else if (input == "d") {
			tree[0] = tree.back();
			tree.pop_back();

			adjust(tree); //정렬
		}
		//r : 루트에서 왼쪽자식 따라가며 키값 출력
		else if (input == "r") {
			int i = 0;
			while (true) {
				if (i > tree.size() - 1) break;
				f_write << tree[i] << ' ';
				if (i == 0) {
					i++;
				}
				else {
					i = i * 2 + 1;
				}
			}
			f_write << '\n';
		}
		//숫자 key값
		else {
			int key;
			stringstream ssInt(input);
			ssInt >> key;
			tree.push_back(key);

			tree_sort(tree); //정렬
		}
	}

	return 0;
}