#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int x, y;
};

int N;
int space[21][21] = { 0, };
vector<Node> fishes;
vector<Node>::iterator it;
int sharkX, sharkY, sharkSize = 2, sharkScale = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> space[i][j];

			if (space[i][j] == 9) { // 상어 위치
				sharkX = i;
				sharkY = j;
				space[i][j] = 0;
			}
			else if (space[i][j] != 0) { // 물고기 위치
				fishes.push_back({ i, j });
			}
		}
	}

	//물고기가 한마리도 없는 경우
	if (fishes.size() == 0) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	while (1) {
		int dist[21][21] = { 0, };
		dist[sharkX][sharkY] = 1;
		queue<Node> q;
		q.push({ sharkX, sharkY });

		// 거리 계산
		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (space[nx][ny] > sharkSize) continue;
				if (dist[nx][ny] != 0) continue;

				q.push({ nx, ny });
				dist[nx][ny] = dist[now.x][now.y] + 1;
			}
		}

		int x = -1, y = -1, dis = 987654321;
		for (it = fishes.begin(); it != fishes.end(); ++it) {
			int now = dist[it->x][it->y];

			if (now == 0) continue; // 도달할 수 없는 물고기
			if (space[it->x][it->y] == sharkSize) continue; //지나갈 순 있는데 못먹는 물고기
			
			if (dis > now) { // 더 가까이 있는 물고기 발견
				x = it->x;
				y = it->y;
				dis = now;
			}
			else if (dis == now) {
				if (x == it->x) { // x 좌표가 같으면
					if (y > it->y) { // y 좌표가 작은거
						x = it->x;
						y = it->y;
					}
				}
				else if (x > it->x) { // x 좌표가 작은거
					x = it->x;
					y = it->y;
				}
			}
		}

		if (x == -1 && y == -1) break; // 먹을 수 있는게 없으면

		for (it = fishes.begin(); it != fishes.end(); ) {
			if (it->x == x && it->y == y) it = fishes.erase(it);
			else ++it;
		}

		

		ans += dist[x][y] - 1;
		space[x][y] = 0;
		sharkScale++;
		sharkX = x;
		sharkY = y;
		if (sharkScale == sharkSize) {
			sharkScale = 0;
			sharkSize++;
		}

		if (fishes.size() == 0) break;
		
	}
	cout << ans;


	return 0;
}
