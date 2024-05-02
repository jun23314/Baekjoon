#include <cstdio>
#include <queue>
#include <string.h>

struct Node {
	int row, col, hei;
};
int box[100][100][100];
bool visited[100][100][100] = { 0, };
int x[6] = { 0,0,-1,1,0,0 };
int y[6] = { -1,1,0,0,0,0 };
int z[6] = { 0,0,0,0,-1,1 };
std::queue<Node> q;
int main() {
	int n, m, h;
	scanf("%d %d %d", &m, &n, &h);
	memset(box, -1, sizeof(box));

	int cnt = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				scanf("%d", &box[j][k][i]);
				if (box[j][k][i] == -1 || box[j][k][i] == 1) cnt++;
				if (box[j][k][i] == 1) q.push({ j, k, i });
			}
			
		}
	}

	q.push({ -1, -1, -1 });

	int total = n * m * h - cnt;
	if (total == 0) {
		printf("0");
		return 0;
	}

	int date = 0;
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		int row = tmp.row;
		int col = tmp.col;
		int hei = tmp.hei;
		if (row == -1 && col == -1 && hei == -1) { // 하루가 지남
			if (q.empty()) break;
			date++;
			q.push({ -1,-1,-1 });
			continue;
		}

		for (int i = 0; i < 6; ++i) {
			int tmp_row = row + x[i];
			int tmp_col = col + y[i];
			int tmp_hei = hei + z[i];
			if (tmp_row < 0 || tmp_row >= n) continue;
			if (tmp_col < 0 || tmp_col >= m) continue;
			if (tmp_hei < 0 || tmp_hei >= h) continue;

			if (box[tmp_row][tmp_col][tmp_hei] == 0) {
				box[tmp_row][tmp_col][tmp_hei] = 1;
				q.push({ tmp_row, tmp_col, tmp_hei });
				total--;
			}
		}
	}

	if (total != 0) printf("-1");
	else printf("%d", date);

	return 0;
}