#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Node {
	int s, e;
};

queue<Node> q;
int paper[505][505] = { 0, };
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };

int bfs(int n, int m) {
	int cnt = 1;
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int cur_i = tmp.s;
		int cur_j = tmp.e;

		for (int i = 0; i < 4; ++i) {
			int next_i = cur_i + x[i];
			int next_j = cur_j + y[i];
			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
			if (paper[next_i][next_j] == 1) {
				paper[next_i][next_j] = 0;
				q.push({ next_i, next_j });
				cnt++;
			}
		}
	}

	return cnt;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) // 세로
		for (int j = 0; j < m; ++j) // 가로
			scanf("%d", &paper[i][j]);

	int cnt = 0;
	int max_size = 0;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {
			if (paper[i][j] == 1) {
				paper[i][j] = 0;
				q.push({ i, j });
				max_size = max(max_size, bfs(n, m));
				cnt++;
			}
		}

	printf("%d\n%d", cnt, max_size);
			
	return 0;
}