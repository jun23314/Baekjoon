#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int a, b, c, d;
int arr[105][105] = { 0, };
int visited[105][105] = { 0, };
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> pq;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int bfs() {
	int cnt = 1;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (arr[nx][ny] != 0) continue;
			if (visited[nx][ny]) continue;

			q.push({ nx, ny });
			visited[nx][ny] = 1;
			cnt++;
		}
	}
	return cnt;
}


int main() {
	cin >> M >> N >> K;

	while (K--) {
		cin >> a >> b >> c >> d;

		b = M - b;
		d = M - d;
		for (int i = d; i < b; ++i)
			for (int j = a; j < c; ++j) 
				arr[i][j]++; 

	}

	int ans = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = 1;
				pq.push(bfs());
				ans++;
			}
		}
	}

	cout << ans << "\n";
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}