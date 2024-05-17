#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int x, y;
};

int city[105][105];
bool visited[105][105] = { 0, };
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int ans[105] = { 0, };
queue<Node> q;

void bfs(int n) {
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int cur_x = tmp.x;
		int cur_y = tmp.y;

		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + x[i];
			int next_y = cur_y + y[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;

			if (city[next_x][next_y] > 0 && !visited[next_x][next_y]) {
				visited[next_x][next_y] = 1;
				q.push({ next_x, next_y });
			}
		}
	}
}

void initVisitedArr(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = 0;
		}
	}
}

void setCityArr(int n, int target) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (city[i][j] <= target) city[i][j] = 0;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int max_num = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &city[i][j]);
			max_num = max(max_num, city[i][j]);
		}
	}

	for (int k = 0; k < max_num; ++k) {
		int target = k;

		setCityArr(n, target);
		initVisitedArr(n);

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (city[i][j] > 0 && !visited[i][j]) {
					q.push({ i, j });
					visited[i][j] = 1;
					bfs(n);
					cnt++;
				}
			}
		}

		ans[k] = cnt;
	}

	int max_value = -1;

	for (auto k : ans) {
		max_value = max(max_value, k);
	}

	printf("%d", max_value);
}