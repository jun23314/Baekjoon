#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_COST 987654321

using namespace std;

struct Node {
	int end;
	int weight;

	bool operator<(const Node& other) const {
		return weight > other.weight;
	}
};

priority_queue<Node> pq;
int N, M;
int A, B;
int a, b, c;
vector<Node> costs[1001];
int route[1001] = { 0, };

void defineArr() {
	for (int i = 0; i <= N; ++i) {
		route[i] = MAX_COST;
	}
}

void dijkstra() {
	while (!pq.empty()) {
		Node cur_node = pq.top();
		pq.pop();

		int start = cur_node.end;
		int cur_weight = cur_node.weight;

		if (cur_weight > route[start]) continue;

		for (auto v : costs[start]) {
			int new_end = v.end;
			int new_weight = v.weight;

			if (route[new_end] <= cur_weight + new_weight) continue;
			route[new_end] = new_weight + cur_weight;
			pq.push({ new_end, new_weight + cur_weight });
		}
	}

}

int main() {
	cin >> N >> M;

	defineArr();

	for (int m = 0; m < M; ++m) {
		cin >> a >> b >> c;
		costs[a].push_back({ b,c });
	}

	cin >> A >> B;
	pq.push({ A, 0 });
	route[A] = 0;
	dijkstra();
	cout << route[B];
}
