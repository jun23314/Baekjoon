#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, K;
int map[1001][1001];
int v[1001][1001][11];
queue<pair<pair<int, int>, int>> q;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	cin >> n >> m >> K;

	for (int i = 0; i < n; ++i) {
		string input;
		cin >> input;
		for (int j = 0; j < m; ++j) {
			map[i][j] = input[j] - '0';
		}
	}

	q.push({ { 0, 0 }, 0 });
	v[0][0][0] = 1;
	while (!q.empty()) {
		pair<pair<int, int>, int> now = q.front();
		q.pop();

		int x = now.first.first;
		int y = now.first.second;
		int k = now.second;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0) {
				if (v[nx][ny][k] != 0) continue;
				v[nx][ny][k] = v[x][y][k] + 1;
				q.push({ {nx, ny}, k });
			}
			else {
				if (v[nx][ny][k + 1] != 0) continue;
				if (k == K) continue;
				v[nx][ny][k + 1] = v[x][y][k] + 1;
				q.push({ {nx, ny}, k + 1 });
			}
		}
	}

	int ans = 987654321;
	for (int i = 0; i <= K; ++i) {
		if (v[n - 1][m - 1][i] == 0) continue;
		ans = min(ans, v[n - 1][m - 1][i]);
	}
	if (ans == 987654321) ans = -1;

	cout << ans;
	
}