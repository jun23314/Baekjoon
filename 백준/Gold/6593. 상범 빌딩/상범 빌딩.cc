#include <iostream>
#include<queue>

using namespace std;

struct Node {
	int x, y, z, time;
};

int building[31][31][31] = {0,};
int x[6] = { 1,-1,0,0,0,0 };
int y[6] = { 0,0,1,-1,0,0 };
int z[6] = { 0,0,0,0,1,-1 };

int bfs(int l, int r, int c, queue<Node> q) {
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int cur_i = tmp.x;
		int cur_j = tmp.y;
		int cur_k = tmp.z;
		int cur_time = tmp.time;

		for (int i = 0; i < 6; ++i) {
			int next_i = cur_i + x[i];
			int next_j = cur_j + y[i];
			int next_k = cur_k + z[i];
			int next_time = cur_time + 1;

			if (next_i < 0 || next_i >= l || next_j < 0 || next_j >= r || next_k < 0 || next_k >= c) continue;

			if (building[next_i][next_j][next_k] == 2) return next_time;

			if (building[next_i][next_j][next_k] == 0) {
				building[next_i][next_j][next_k] = 1;
				q.push({ next_i, next_j, next_k, next_time });
			}
		}
	}

	return -1;
}

void initArr(int l, int r, int c) {
	for (int i = 0; i < l; ++i) // 층수
		for (int j = 0; j < r; ++j) 
			for (int k = 0; k < c; ++k) 
				building[i][j][k] = -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int l, r, c;
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break;

		initArr(l, r, c);
		queue<Node> q;

		for (int i = 0; i < l; ++i) { // 층수
			for (int j = 0; j < r; ++j) {
				string str;
				cin >> str;

				for (int k = 0; k < c; ++k) {
					if (str[k] == '#') building[i][j][k] = 1;
					else if (str[k] == '.') building[i][j][k] = 0;
					else if (str[k] == 'E') building[i][j][k] = 2;
					else { // S
						q.push({ i, j, k, 0 });
						building[i][j][k] = 1;
					}
				}
			}
		}

		int ans = bfs(l, r, c, q);
		if (ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
			
	return 0;
}