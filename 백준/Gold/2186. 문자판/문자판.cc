#include <iostream>
#include <string.h>

using namespace std;

int n, m, k;
char square[101][101];
bool visited[101][101] = { 0, };
string target_str;
char target[81];
int len = 0;
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };
int ans = 0;
int check[101][101][81];

void inputNumbers() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			square[i][j] = tmp[j];
		}
	}

	cin >> target_str;
	len = target_str.length();
	for (int i = 0; i < len; ++i) {
		target[i] = target_str[i];
	}
}

int findWay(int row, int col, int idx) {
	if (check[row][col][idx] != -1) return check[row][col][idx]; // 이미 구해진 값이면
	if (idx >= len - 1) return 1; // 끝에 도달했으면 +1
	
	int cnt = 0;
	for (int q = 1; q <= k; ++q) {
		for (int p = 0; p < 4; ++p) {
			int tmp_row = row + (x[p] * q);
			if (tmp_row < 0 || tmp_row >= n) continue;
			
			int tmp_col = col + (y[p] * q);
			if (tmp_col < 0 || tmp_col >= m) continue;

			if (target[idx + 1] == square[tmp_row][tmp_col]) {
				cnt += findWay(tmp_row, tmp_col, idx + 1);
			}
		}
	}

	check[row][col][idx] = cnt;
	return cnt;
}

void funcStart() {
	char start = target[0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (square[i][j] == start) {
				ans += findWay(i, j, 0);
			}
		}
	}
}

int main() {
	inputNumbers();
	memset(check, -1, sizeof(check));
	funcStart();
	cout << ans;
	return 0;
}