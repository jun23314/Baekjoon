#include <iostream>
#include <queue>

using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
int dx[2] = { 1, -1 };
int visited[100005] = { 0, };

int main() {
	cin >> n >> k;

	q.push({ 0, n });
	visited[n] = 1;

	while (!q.empty()) {
		int times = q.top().first;
		int now = q.top().second;
		q.pop();

		if (now == k) {
			cout << times;
			return 0;
		}

		for (int i = 0; i < 1; ++i) {
			int next = now * 2;

			if (next > 100000 || next < 0) continue;
			if (visited[next] == 1) continue;

			q.push({ times, next });
			visited[next] = 1;
		}

		for (int i = 0; i < 2; ++i) {
			int next = now + dx[i];

			if (next < 0 || next > 100000) continue;
			if (visited[next] == 1) continue;

			q.push({ times + 1, next });
			visited[next] = 1;
		}
	}

	return 0;
}