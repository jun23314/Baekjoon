#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x, y;
	int height;
};

int N, M;
int h;
int sea[301][301] = { 0, };
int visited[301][301] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int tmp_sea[301][301] = { 0, };
queue<Node> q;

void initArr() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			visited[i][j] = 0;
		}
	}
}

int isConnected() {
	queue<Node> tq;
	bool flag = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (sea[i][j] != 0) {
				tq.push({ i, j, sea[i][j] });
				visited[i][j] = 1;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	while (!tq.empty()) {
		Node tmp = tq.front();
		tq.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];

			if (sea[nx][ny] != 0 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				tq.push({ nx, ny, sea[nx][ny] });
			}
		}
	}

	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();

		if (visited[tmp.x][tmp.y]) continue;
		return 2;
	}
	return 1;
}

void bfs() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			tmp_sea[i][j] = 0;
		}
	}

	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int cur_x = tmp.x;
		int cur_y = tmp.y;
		int cur_height = tmp.height;

		int cnt = 0;
		for (int i = 0; i < 4; ++i) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (sea[new_x][new_y] == 0) cnt++;
			if (cnt == sea[cur_x][cur_y]) break;
		}

		tmp_sea[cur_x][cur_y] = cur_height - cnt;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			sea[i][j] = tmp_sea[i][j];
			if (sea[i][j] != 0) {
				q.push({ i, j, sea[i][j] });
			}
		}
	}
}

void inputQ() {
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			if (sea[i][j] != 0) q.push({ i, j, sea[i][j] });
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> h;
			sea[i][j] = h;
		}
	}

	int year = 1;
	while (1) {
		inputQ();
		bfs();

		if (q.empty()) {
			cout << "0";
			break;
		}

		initArr();
		int ans = isConnected();
		if (ans == 2) {
			cout << year;
			break;
		}

		year++;
	}

	return 0;
}