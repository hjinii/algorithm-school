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

	// weight기준 오름차순 정렬
	bool operator <(Edge &edge) {
		// wegith가 다르다면
		if (this->weight != edge.weight) {
			return this->weight < edge.weight;
		}
		// weight가 같다면 앞에있는 순대로
		else {
			return this->index < edge.index;
		}
	}
};

int n, m;
vector<Edge> kruskal;

// 정점이 속한 부모 찾기
int find(int node, vector<int>& check) {
	if (check[node] == node) return node;
	return find(check[node], check);
}

// 노드 합병
void merge(int node1, int node2, vector<int>& check) {
	node1 = find(node1, check);
	node2 = find(node2, check);
	check[node2] = node1; //합병
}

// 사이클 존재 여부 확인
bool isCycle(int node1, int node2, vector<int>& check) {
	node1 = find(node1, check);
	node2 = find(node2, check);
	if (node1 == node2) return true; //사이클 존재 O
	else return false; //사이클 존재 X
}

int main(void) {
	f_read >> n >> m;

	//--초기화--
	for (int i = 0; i < m; i++) {
		int u, v, w;
		f_read >> u >> v >> w;
		kruskal.push_back(Edge(u, v, w, i));
	}
	
	// weight기준 오름차순 정렬
	sort(kruskal.begin(), kruskal.end());

	// 각 노드 독립적 트리로 초기화
	vector<int> check(n);
	for (int i = 0; i < n; i++) {
		check[i] = i;
	}

	int result = 0;
	vector<int> p_edge(n-1);
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (j == n - 1) break;
		// 사이클 X -> 가중치 더함
		if (!isCycle(kruskal[i].node[0], kruskal[i].node[1], check)) {
			result += kruskal[i].weight;
			// 노드 합병
			merge(kruskal[i].node[0], kruskal[i].node[1], check);
			// 선택된 인덱스 기록
			p_edge[j] = kruskal[i].index;
			j++;
		}
	}

	// 출력
	f_write << result << '\n';
	for (int i = 0; i < n-1; i++) {
		f_write << p_edge[i] << '\n';
	}

	return 0;
}