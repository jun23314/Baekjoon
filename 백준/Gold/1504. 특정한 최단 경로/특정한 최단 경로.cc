#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_COST 900000

using namespace std;

struct Node {
	int end;
	int cost;

	bool operator<(const Node& other) const {
		return cost > other.cost;
	}
};

priority_queue<Node> pq;
vector<Node> route[801];
int N, E;
int a, b, c;
int v1, v2;
int costs[801] = { 0, };

void initArr() {
	for (int i = 0; i <= N; ++i) costs[i] = MAX_COST;
}

int main() {
	cin >> N >> E;

	while (E--) {
		cin >> a >> b >> c;
		route[a].push_back({ b,c });
		route[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	initArr();
	pq.push({ 1, 0 });
	costs[1] = 0;
	while (!pq.empty()) {
		Node tmp = pq.top();
		pq.pop();

		int start = tmp.end;
		int cost = tmp.cost;
		if (costs[start] < cost) continue;

		for (auto i : route[start]) {
			if (costs[i.end] <= cost + i.cost) continue;

			costs[i.end] = cost + i.cost;
			pq.push({ i.end, costs[i.end] });
		}
	}

	int s_a = costs[v1];
	int s_b = costs[v2];

	if (s_a == MAX_COST && s_b == MAX_COST) {
		cout << "-1";
		return 0;
	}

	initArr();
	costs[v1] = 0;
	pq.push({ v1, 0 });

	while (!pq.empty()) {
		Node tmp = pq.top();
		pq.pop();

		int start = tmp.end;
		int cost = tmp.cost;
		if (costs[start] < cost) continue;

		for (auto i : route[start]) {
			if (costs[i.end] <= cost + i.cost) continue;

			costs[i.end] = cost + i.cost;
			pq.push({ i.end, costs[i.end] });
		}
	}

	int m_a_n = costs[N];
	int m_a_b = costs[v2];
	if (m_a_n == MAX_COST && m_a_b == MAX_COST) {
		cout << "-1";
		return 0;
	}

	initArr();
	costs[v2] = 0;
	pq.push({ v2, 0 });

	while (!pq.empty()) {
		Node tmp = pq.top();
		pq.pop();

		int start = tmp.end;
		int cost = tmp.cost;
		if (costs[start] < cost) continue;

		for (auto i : route[start]) {
			if (costs[i.end] <= cost + i.cost) continue;

			costs[i.end] = cost + i.cost;
			pq.push({ i.end, costs[i.end] });
		}
	}

	int e_n = costs[N];
	int e_a = costs[v1];

	if (e_n == MAX_COST && e_a == MAX_COST) {
		cout << "-1";
		return 0;
	}

	int A = s_a + m_a_b + e_n;
	int B = s_b + m_a_n + e_a;

	if (s_a == MAX_COST || m_a_b == MAX_COST || e_n == MAX_COST) {
		cout << "-1";
		return 0;
	}
	if (s_b == MAX_COST || m_a_n == MAX_COST || e_a == MAX_COST) {
		cout << "-1";
	}

	cout << min(A, B);
	return 0;
}