#include <iostream>
#include<queue>
#include<algorithm>
#define INF 1000

using namespace std;

struct Node {
	int x, y, time;
};

int miro[1005][1005] = {0,};
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };
int fires[1005][1005] = { 0, };
int visited[1005][1005] = { 0, };
queue<Node> q;
queue<Node> fire;

int bfs(int r, int c) {
	int init = 0;
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int cur_i = tmp.x;
		int cur_j = tmp.y;
		int cur_time = tmp.time;
		
		if ((cur_i == 0 || cur_i == r - 1 || cur_j == 0 || cur_j == c - 1) && fires[cur_i][cur_j] > cur_time) return cur_time + 1;

		for (int i = 0; i < 4; ++i) {
			int next_i = cur_i + x[i];
			int next_j = cur_j + y[i];
			int next_time = cur_time + 1;

			if (next_i < 0 || next_i >= r || next_j < 0 || next_j >= c) continue;

			if ((miro[next_i][next_j] == 0 || miro[next_i][next_j] == 10) && fires[next_i][next_j] > next_time) {
				if(miro[next_i][next_j] == 0) miro[next_i][next_j] = 3;
				q.push({ next_i, next_j, next_time });
			}
		}
	}

	return -1;
}

void bfs_fire(int r, int c) {
	while (!fire.empty()) {
		Node tmp = fire.front();
		fire.pop();
		int cur_i = tmp.x;
		int cur_j = tmp.y;
		int cur_time = tmp.time;

		for (int i = 0; i < 4; ++i) {
			int next_i = cur_i + x[i];
			int next_j = cur_j + y[i];
			int next_time = cur_time + 1;

			if (next_i < 0 || next_i >= r || next_j < 0 || next_j >= c) continue;

			if ((miro[next_i][next_j] == 0 || miro[next_i][next_j] == 3) && visited[next_i][next_j] == 0) {
				fire.push({ next_i, next_j, next_time });
				visited[next_i][next_j] = 1;
				fires[next_i][next_j] = min(fires[next_i][next_j], next_time);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			fires[i][j] = INF;
		}
	}

	for (int i = 0; i < r; ++i) {
		string str;
		cin >> str;

		for (int j = 0; j < c; ++j) {
			if (str[j] == '#') {
				miro[i][j] = 1; // 벽
			}
			else if (str[j] == '.') {
				miro[i][j] = 0;
			}
			else if (str[j] == 'F') {
				miro[i][j] = 2;
				fires[i][j] = 0;
				visited[i][j] = 1;
				fire.push({ i, j });
			}
			else { // J
				miro[i][j] = 3;
				q.push({ i, j, 0 });
			}
		}
	}

	bfs_fire(r, c);

	int ans = bfs(r, c);
	if (ans == -1) cout << "IMPOSSIBLE";
	else cout << ans;

	return 0;
}