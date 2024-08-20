#include<iostream>
#include <queue>

using namespace std;

struct Node {
	int x, y;
	double times;
	int dust;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int R, C, T;
int room[51][51] = { 0, };
queue<Node> q;
queue<pair<int, int>> air;
pair<int, int> airCleaner_up;
pair<int, int> airCleaner_down;

void rotateDust(double time) {
	while (1) {
		Node tmp = q.front();
		if (tmp.times == time) return;
		q.pop();

		int cur_x = tmp.x;
		int cur_y = tmp.y;
		int cur_times = tmp.times;
		int cur_dust = room[cur_x][cur_y];
		int new_dust = cur_dust / 5;
		int cnt = 0;

		if (new_dust <= 0) {
			q.push({ cur_x, cur_y, time, cur_dust });
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			
			if (new_x < 1 || new_y < 1 || new_x > R || new_y > C) continue;
			if (new_x == airCleaner_up.first && new_y == 1) continue;
			if (new_x == airCleaner_down.first && new_y == 1) continue;

			q.push({ new_x, new_y, time, new_dust });
			cnt++;
			
		}
		cur_dust = cur_dust - new_dust * cnt;
		q.push({ cur_x, cur_y, time, cur_dust });
	}
}

void runAirCleaner(int time) {
	while (1) {
		Node tmp = q.front();
		if (tmp.times == (double) time) return;
		q.pop();

		int cur_x = tmp.x;
		int cur_y = tmp.y;
		int cur_times = tmp.times;
		int cur_dust = tmp.dust;

		if (cur_x == 1 || cur_x == R) { // 위아래
			if (cur_x == 1 && cur_y == 1) q.push({ cur_x + 1, cur_y, (double)time, cur_dust });
			else if (cur_x == R && cur_y == 1) q.push({ cur_x - 1, cur_y, (double)time, cur_dust });
			else q.push({ cur_x, cur_y - 1, (double)time, cur_dust });
		}
		else if (cur_x == airCleaner_up.first || cur_x == airCleaner_down.first) {
			if (cur_x == airCleaner_up.first && cur_y == C) q.push({ cur_x - 1, cur_y, (double)time, cur_dust });
			else if (cur_x == airCleaner_down.first && cur_y == C) q.push({ cur_x + 1, cur_y, (double)time, cur_dust });
			else q.push({ cur_x, cur_y + 1, (double)time, cur_dust });
		}
		else if (cur_x <= airCleaner_up.first) {
			if (cur_y == C) {
				if (cur_x == 1) q.push({ cur_x, cur_y - 1, (double)time, cur_dust });
				else q.push({ cur_x - 1, cur_y, (double)time, cur_dust });
			}
			else if (cur_y == 1) q.push({ cur_x + 1, cur_y, (double)time, cur_dust });
			else q.push({ cur_x, cur_y, (double)time, cur_dust });

		}
		else if (cur_x >= airCleaner_down.first) {
			if (cur_y == C) {
				if (cur_x == R) q.push({ cur_x, cur_y - 1, (double)time, cur_dust });
				else q.push({ cur_x + 1, cur_y, (double)time, cur_dust });
			}
			else if (cur_y == 1) q.push({ cur_x - 1, cur_y, (double)time, cur_dust });
			else q.push({ cur_x, cur_y, (double)time, cur_dust });
		}
	}
}

void initArr() {
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (room[r][c] == -1) continue;
			room[r][c] = 0;
		}
	}
}

void checkRoom() {
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();

		int cur_x = tmp.x;
		int cur_y = tmp.y;
		int cur_dust = tmp.dust;
		
		if (room[cur_x][cur_y] == -1) continue;
		room[cur_x][cur_y] += cur_dust;
	}
}

void pushQueue(double time) {
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (room[r][c] == -1 || room[r][c] == 0) continue;
			q.push({ r, c, time, room[r][c] });
		}
	}
}

int checkDust() {
	int cnt = 0;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (room[r][c] == -1 || room[r][c] == 0) continue;
			cnt += room[r][c];
		}
	}

	return cnt;
}

int main() {
	cin >> R >> C >> T;

	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			cin >> room[r][c];
			if (room[r][c] == -1) air.push({r, c});
			else if (room[r][c] != 0) q.push({ r, c, (double) 0, room[r][c]});
		}
	}

	for (int j = 0; j < 2; ++j) {
		pair<int, int> tmps = air.front();
		air.pop();
		if (j == 0) airCleaner_up = tmps;
		else airCleaner_down = tmps;
		air.push(tmps);
	}

	for (int t = 1; t <= T; ++t) {
		rotateDust((double) t - 0.5);

		initArr();
		checkRoom();
		pushQueue((double) t - 0.5);

		runAirCleaner(t);
		initArr();
		checkRoom();
		pushQueue((double) t);
	}

	cout << checkDust();

	return 0;
}