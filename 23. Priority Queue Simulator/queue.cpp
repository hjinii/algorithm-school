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
	//child�� parent�� ���ϸ鼭 ����
	int i;
	i = tree.size() - 1;
	while (i > 0) {
		if (i % 2 != 0) { //Ȧ��
			if (tree[i] <= tree[(i-1) / 2]) break;
			else {
				int tmp = tree[i];
				tree[i] = tree[(i-1) / 2];
				tree[(i-1) / 2] = tmp;

				i = (i-1) / 2;
			}
		}
		else { //¦��
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
		//�ڽľ��� ������ ����̸� ����
		if ((i * 2 + 1) > (tree.size()-1)  && (i * 2 + 2) > (tree.size()-1)) break;
		else {
			//���� �ڽ� ������
			if ((i * 2 + 2) > (tree.size() - 1)) {
				int tmp = tree[i];
				tree[i] = tree[i * 2 + 1];
				tree[i * 2 + 1] = tmp;
				break;
			}
			//�¿��� �ڽ� ��� ������
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
		//d : root����, ������ Ű�� ��Ʈ�� �ø��� adjust�˰���
		else if (input == "d") {
			tree[0] = tree.back();
			tree.pop_back();

			adjust(tree); //����
		}
		//r : ��Ʈ���� �����ڽ� ���󰡸� Ű�� ���
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
		//���� key��
		else {
			int key;
			stringstream ssInt(input);
			ssInt >> key;
			tree.push_back(key);

			tree_sort(tree); //����
		}
	}

	return 0;
}