#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
	int x, y;
    int dir;
};

int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int ans = 0;

void move(int sharkX, int sharkY, int sharkDir, int cnt, int m[][4], Fish f[]) {
	int fishMap[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			fishMap[i][j] = m[i][j];
		}
	}

	Fish fishes[17];
	for (int i = 1; i < 17; ++i) {
		fishes[i] = f[i];
	}

	// move
	for (int i = 1; i < 17; ++i) {

		if (fishes[i].dir == 8) continue;

		Fish origin = fishes[i];
		int num = fishMap[origin.x][origin.y];
		int dirCnt = 0;

		while (1) {
			int nx = fishes[i].x + dx[fishes[i].dir];
			int ny = fishes[i].y + dy[fishes[i].dir];
			
			if (nx < 0 || ny >= 4 || ny < 0 || nx >= 4 || (nx == sharkX && ny == sharkY)) {
				fishes[i].dir = (fishes[i].dir + 1) % 8;
				
				if (++dirCnt == 8) break;
				continue;
			}

			if (fishMap[nx][ny] == 0) {
				fishMap[nx][ny] = num;
				fishes[num].x = nx;
				fishes[num].y = ny;
				fishMap[origin.x][origin.y] = 0;
				break;
			}

			int change_num = fishMap[nx][ny];

			fishMap[origin.x][origin.y] = change_num;
			fishMap[nx][ny] = num;

			fishes[i].x = nx;
			fishes[i].y = ny;

			fishes[change_num].x = origin.x;
			fishes[change_num].y = origin.y;

			break;
		}
	}
    
    //eat
	bool flag = false;
	for (int i = 1; i < 4; ++i) {
		int x = sharkX + dx[sharkDir] * i;
		int y = sharkY + dy[sharkDir] * i;

		if (y < 0 || y >= 4 || x < 0 || x >= 4 || fishMap[x][y] == 0) {	// 상어 이동 못함
			continue;
		}

		flag = true;

		int fishNum = fishMap[x][y];
		Fish origin = fishes[fishNum];

		fishes[fishNum] = { 4, 4, 8 };
		fishMap[x][y] = 0;

		move(x, y, origin.dir, cnt + fishNum, fishMap, fishes);

		fishes[fishNum] = { origin.x, origin.y, origin.dir };
		fishMap[x][y] = fishNum;
	}

	if (!flag) ans = max(ans, cnt);
}


int main() {
	int map[4][4];
	Fish fish[17];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int num, dir;
			cin >> num >> dir;
			map[i][j] = num;
			fish[num] = { i, j, --dir };
		}
	}

	int num = map[0][0];
	int sharkDir = fish[num].dir;

	fish[num] = { 4,4,8 };
	map[0][0] = 0;

	move(0, 0, sharkDir, num, map, fish);

	cout << ans;

	return 0;
}