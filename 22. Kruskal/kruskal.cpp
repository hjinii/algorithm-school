#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream f_read("kruskal.inp");
ofstream f_write("kruskal.out");

class Edge {
public:
	int node[2];
	int weight, index;
	Edge(int u, int v, int w, int i) {
		this->node[0] = u;
		this->node[1] = v;
		this->weight = w;
		this->index = i;
	}

	// weight���� �������� ����
	bool operator <(Edge &edge) {
		// wegith�� �ٸ��ٸ�
		if (this->weight != edge.weight) {
			return this->weight < edge.weight;
		}
		// weight�� ���ٸ� �տ��ִ� �����
		else {
			return this->index < edge.index;
		}
	}
};

int n, m;
vector<Edge> kruskal;

// ������ ���� �θ� ã��
int find(int node, vector<int>& check) {
	if (check[node] == node) return node;
	return find(check[node], check);
}

// ��� �պ�
void merge(int node1, int node2, vector<int>& check) {
	node1 = find(node1, check);
	node2 = find(node2, check);
	check[node2] = node1; //�պ�
}

// ����Ŭ ���� ���� Ȯ��
bool isCycle(int node1, int node2, vector<int>& check) {
	node1 = find(node1, check);
	node2 = find(node2, check);
	if (node1 == node2) return true; //����Ŭ ���� O
	else return false; //����Ŭ ���� X
}

int main(void) {
	f_read >> n >> m;

	//--�ʱ�ȭ--
	for (int i = 0; i < m; i++) {
		int u, v, w;
		f_read >> u >> v >> w;
		kruskal.push_back(Edge(u, v, w, i));
	}
	
	// weight���� �������� ����
	sort(kruskal.begin(), kruskal.end());

	// �� ��� ������ Ʈ���� �ʱ�ȭ
	vector<int> check(n);
	for (int i = 0; i < n; i++) {
		check[i] = i;
	}

	int result = 0;
	vector<int> p_edge(n-1);
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (j == n - 1) break;
		// ����Ŭ X -> ����ġ ����
		if (!isCycle(kruskal[i].node[0], kruskal[i].node[1], check)) {
			result += kruskal[i].weight;
			// ��� �պ�
			merge(kruskal[i].node[0], kruskal[i].node[1], check);
			// ���õ� �ε��� ���
			p_edge[j] = kruskal[i].index;
			j++;
		}
	}

	// ���
	f_write << result << '\n';
	for (int i = 0; i < n-1; i++) {
		f_write << p_edge[i] << '\n';
	}

	return 0;
}