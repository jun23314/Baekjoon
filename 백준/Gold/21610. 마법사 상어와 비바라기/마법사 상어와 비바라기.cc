#include<iostream>
#include <queue>

using namespace std;

int N, M;
int map[51][51];
bool v[51][51] = { 0, };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
queue<pair<int, int>> cloud;
queue<pair<int, int>> forRemove;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	//초기 구름
	cloud.push(make_pair(N - 1, 0));
	cloud.push(make_pair(N - 1, 1));
	cloud.push(make_pair(N - 2, 0));
	cloud.push(make_pair(N - 2, 1));
	
	for (int m = 0; m < M; ++m) {
		int dir, size;
		cin >> dir >> size;

		size %= N;
		//구름 이동
		int leng = cloud.size();

		for (int i = 0; i < leng; ++i) {
			pair<int, int> now = cloud.front();
			cloud.pop();

			int nx = now.first + (dx[dir] * size);
			int ny = now.second + (dy[dir] * size);

			if (nx >= N) nx %= N;
			else if(nx < 0) nx = N + (nx % N);

			if (ny >= N) ny %= N;
			else if (ny < 0) ny = N + (ny % N);

			cloud.push(make_pair(nx, ny));
		}

		//비가 내려
		for (int i = 0; i < leng; ++i) {
			pair<int, int> now = cloud.front();
			cloud.pop();

			map[now.first][now.second]++;
			cloud.push({ now.first, now.second });
		}

		// 물복사 버그
		while(!cloud.empty()) {
			pair<int, int> now = cloud.front();
			cloud.pop();

			v[now.first][now.second] = true;
			forRemove.push({ now.first, now.second });

			int cnt = 0;
			for (int j = 2; j < 9; j += 2) {
				int nx = now.first + dx[j];
				int ny = now.second + dy[j];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (map[nx][ny] == 0) continue;
				cnt++;
			}

			if (cnt == 0) continue;

			map[now.first][now.second] += cnt;
		}
	
		// 2이상 칸에 구름 생성 후 물 양 감소(사라진 칸 아니어야 함)
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] < 2) continue;
				if (v[i][j]) continue;

				cloud.push({ i, j });
				map[i][j] -= 2;
			}
		}

		// 방문 배열 초기화
		while (!forRemove.empty()) {
			pair<int, int> now = forRemove.front();
			forRemove.pop();

			v[now.first][now.second] = false;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans += map[i][j];
		}
	}

	cout << ans;
	return 0;
}