#include <cstdio>
#include <queue>

using namespace std;

struct BALL {
	int r, c, m, s, d;
};

static int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
static int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
int a, b, c, e, f;
queue<BALL> fireballs;
queue<BALL> map[51][51];

void moveBalls() {
	int leng = fireballs.size();
	for (int i = 0; i < leng; ++i) {
		BALL nb = fireballs.front();
		fireballs.pop();

		int nr = nb.r + dx[nb.d] * nb.s;
		int nc = nb.c + dy[nb.d] * nb.s;
		fireballs.push({ (nr % N + N) % N, (nc % N + N) % N, nb.m, nb.s, nb.d });
	}
}

void initMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			while (!map[i][j].empty()) map[i][j].pop();
		}
	}
}

void checkBalls() {
	initMap();
	
	while (!fireballs.empty()) {
		BALL nb = fireballs.front();
		
		map[nb.r][nb.c].push(fireballs.front());
		fireballs.pop();
	}
}

void findDuplicatedBalls() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].empty() || map[i][j].size() == 0) continue;
			
			if (map[i][j].size() == 1) {
				fireballs.push(map[i][j].front());
				map[i][j].pop();
				continue;
			}
			BALL ball = map[i][j].front();
			int sm = ball.m, ss = ball.s, sd = ball.d;
			map[i][j].pop();
			int leng = map[i][j].size();

			bool flag = false;
			for (int k = 0; k < leng; ++k) {
				sm += map[i][j].front().m;
				ss += map[i][j].front().s;

				if (!flag && (map[i][j].front().d % 2 == sd % 2)) {
					map[i][j].pop();
					continue;
				}
				else flag = true;

				map[i][j].pop();
			}

			int nm = sm / 5;
			int ns = ss / (leng + 1);
			
			if (nm < 1) {
				while (!map[i][j].empty()) map[i][j].pop();
				continue;
			}

			if (flag) { // 1 3 5 7
				fireballs.push({ i, j, nm, ns, 1 });
				fireballs.push({ i, j, nm, ns, 3 });
				fireballs.push({ i, j, nm, ns, 5 });
				fireballs.push({ i, j, nm, ns, 7 });
			}
			else {
				fireballs.push({ i, j, nm, ns, 0 });
				fireballs.push({ i, j, nm, ns, 2 });
				fireballs.push({ i, j, nm, ns, 4 });
				fireballs.push({ i, j, nm, ns, 6 });
			}

			while (!map[i][j].empty()) map[i][j].pop();

		}
	}
}

void solve() {
	while (K-- != 0) {
		moveBalls();
		checkBalls();
		findDuplicatedBalls();
	}
}


void input() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d %d %d", &a, &b, &c, &e, &f);
		fireballs.push({ a - 1, b - 1, c, e, f });
	}
}

void output() {
	int ans = 0;
	while (!fireballs.empty()) {
		ans += fireballs.front().m;
		fireballs.pop();
	}
	printf("%d", ans);
}

int main() {
	
	input();
	solve();
	output();
	return 0;

}