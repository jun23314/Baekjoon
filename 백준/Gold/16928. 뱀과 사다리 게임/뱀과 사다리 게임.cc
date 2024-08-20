#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
	int cnt;
	int kan;

	bool operator<(const Node& other) const {
		if (cnt == other.cnt) return kan < other.kan;
		return cnt > other.cnt;
	}
};

int N, M;
int x, y;
int visited[101] = { 0, };
unordered_map<int, int> m;
priority_queue<Node> pq;
int moving[6] = { 1,2,3,4,5,6 };

int bfs() {
	while (!pq.empty()) {
		Node cur_node = pq.top();
		pq.pop();

		int cur_cnt = cur_node.cnt;
		int cur_kan = cur_node.kan;

		if (cur_kan == 100) return cur_cnt;

		for (int i = 0; i < 6; ++i) {
			int new_kan = cur_kan + moving[i];
			if (visited[new_kan]) continue;
			if (m.find(new_kan) != m.end()) new_kan = m[new_kan];

			if (new_kan > 100) continue;

			pq.push({ cur_cnt + 1, new_kan });
			visited[new_kan] = 1;
		}


	}

	return -1;
}

int main() {
	cin >> N >> M;
	int total = N + M;

	for (int i = 0; i < total; ++i) {
		cin >> x >> y;
		m[x] = y;
	}

	pq.push({ 0, 1 });
	visited[1] = 1;
	
	cout << bfs();

	return 0;
}