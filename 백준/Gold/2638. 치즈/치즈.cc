#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> cheese;
queue<pair<int, int>> out;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	out.push({ 0, 0 });
	visited[0][0] = true;
	
	int day = 0;
	while (1) {

		//공기 설정
		while (!out.empty()) {

			pair<int, int> now = out.front();
			out.pop();

			int x = now.first;
			int y = now.second;


			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] == 1) continue;
				if (visited[nx][ny]) continue;

				out.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}

		// 녹을 치즈 찾기
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visited[i][j]) continue; // 공기
				if (map[i][j] == 0) continue; //실내 공기

				// 방문 안한 치즈
				int cnt = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					
					if (visited[nx][ny]) cnt++;
				}

				if (cnt >= 2) cheese.push({ i, j });
			}
		}

		if (cheese.empty()) break;

		// 치즈 녹이기
		while (!cheese.empty()) {
			pair<int, int> now = cheese.front();
			cheese.pop();

			map[now.first][now.second] = 0;
			visited[now.first][now.second] = true;
			out.push(now);
		}

		day++;

	}

	cout << day;

}