#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Bus {
	int start;
	int cost;

	bool operator<(const Bus b) const {
		return this->cost > b.cost; // 비용 오름차순
	}
};

priority_queue<Bus> pq;
vector<pair<int, int>> city[1001];
vector<pair<int, int>>::iterator it;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		city[s].push_back({ e, c });
	}

	int s, e;
	cin >> s >> e;

	int cost[1001] = { 0, };
	fill(cost, cost + n + 1, INF);
	cost[s] = 0;

	int route[1001] = { 0, };

	pq.push({ s, 0 });
	while (!pq.empty()) {
		Bus now = pq.top();
		pq.pop();

		int start = now.start;
		int c = now.cost;

		if (cost[start] < c) continue;

		for (it = city[start].begin(); it != city[start].end(); ++it) {
			int dest = it->first;
			int destCost = it->second;

			if (cost[dest] > c + destCost) {
				cost[dest] = c + destCost;
				pq.push({ dest, c + destCost });
				route[dest] = start;
			}
		}
	}

	cout << cost[e] << "\n";

	vector<int> ans;
	ans.push_back(e);
	
	while (1) {
		int now = route[e];
		if (now == 0) break;

		e = now;
		ans.push_back(e);
		
	}

	cout << ans.size() << "\n";

	while (!ans.empty()) {
		cout << ans.back() << " ";
		ans.pop_back();
	}

	
}

