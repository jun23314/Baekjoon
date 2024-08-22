#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#define MAX_COST 987654321

using namespace std;

struct Node {
	int end;
	int weight;

	bool operator<(const Node& other) const {
		return weight > other.weight;
	}
};

int V, E;
int K;
int u, v, w;
int costs[200001] = { 0, };
unordered_map<int, int> route[20001];
priority_queue<Node> ans;

int main() {
	cin >> V >> E;
	cin >> K;

	while (E--) {
		cin >> u >> v >> w;
		if (route[u].find(v) == route[u].end()) route[u][v] = w;
		else route[u][v] = min(route[u][v], w);
	}

	for (int i = 0; i <= V; ++i) {
		costs[i] = MAX_COST;
	}

	costs[K] = 0;
	ans.push({K, 0});

	while (!ans.empty()) {
		Node tmp = ans.top();
		ans.pop();

		int start = tmp.end;
		int cost = tmp.weight;

		if (costs[start] < cost) continue;

		for (auto i : route[start]) {
			int end = i.first;
			int now_cost = i.second;

			if (costs[end] <= cost + now_cost) continue;

			costs[end] = cost + now_cost;
			ans.push({ end, costs[end] });
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (costs[i] == MAX_COST) cout << "INF\n";
		else cout << costs[i] << "\n";
	}

}


