#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
queue<int> q;
int info[401][4];
int classRoom[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int score[5] = { 0, 1, 10, 100, 1000 };

//
// 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
// 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
// 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
//

void check(int input) {
	int isEmpty = 0;
	int isLike = 0;
	int row = -1;
	int col = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (classRoom[i][j] != 0) continue;

			int emptyCnt = 0;
			int likeCnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (classRoom[nx][ny] == 0) emptyCnt++;
				for (int x = 0; x < 4; ++x) {
					if (classRoom[nx][ny] == info[input][x]) {
						likeCnt++;
						break;
					}
				}
			}

			if (isLike > likeCnt) continue;
			else if (isLike < likeCnt) {
				isLike = likeCnt;
				row = i;
				col = j;
				isEmpty = emptyCnt;
			}
			else {
				if (isEmpty > emptyCnt) continue;
				else if (isEmpty < emptyCnt) {
					row = i;
					col = j;
					isEmpty = emptyCnt;
				}	
				else {
					if (emptyCnt == 0 && likeCnt == 0 && row == -1) {
						row = i;
						col = j;
					}
				}
			}
		}
	}

	classRoom[row][col] = input;
}

int cal() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int now = classRoom[i][j];
			int likeCnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				for (int x = 0; x < 4; ++x) {
					if (classRoom[nx][ny] == info[now][x]) {
						likeCnt++;
						break;
					}
				}
			}

			sum += score[likeCnt];
		}
	}

	return sum;
}

int main() {
	// input
	cin >> n;
	int how = n*n;
	for (int i = 0; i < how; ++i) {
		int num;
		cin >> num;
		q.push(num);

		for (int j = 0; j < 4; ++j) {
			cin >> info[num][j];
		}
	}


	//solve
	//시작은 무조건 (1,1)
	int num = q.front();
	classRoom[1][1] = num;
	q.pop();

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		check(now);
	}

	

	int ans = cal();
	cout << ans;
}