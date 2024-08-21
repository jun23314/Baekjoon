#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int times;
	int location;

	bool operator<(const Node& other) const {
		if (other.times == times) return location < other.location;
		return times > other.times;
	}
};

int n, m;
priority_queue<Node> q;
int visited[100001] = { 0, };
int timing[100001] = { 0, };
int ans_time = -1;
int ans_cnt = 0;

void bfs() {
	while (!q.empty()) {
		Node tmp = q.top();
		q.pop();

		int cur_times = tmp.times;
		int cur_loc = tmp.location;

		if (cur_loc == m) {
			if (ans_time != -1) { // 최소시간 확정 후
				if (ans_time < cur_times) continue;
				ans_cnt++;
				continue;
			}
			else { // 최초 도달
				ans_time = cur_times;
				ans_cnt++;
				continue;
			}
		}

		int new_loc = cur_loc + 1;
		if (new_loc >= 0 && new_loc <= 100000) {
			if (!visited[new_loc]) {
				q.push({ cur_times + 1, new_loc });
				if (new_loc != m) visited[new_loc] = 1;
				timing[new_loc] = cur_times + 1;
			}
			else {
				if (timing[new_loc] == cur_times + 1) {
					q.push({ cur_times + 1, new_loc });
				}

			}
		}

		new_loc = cur_loc - 1;
		if (new_loc >= 0 && new_loc <= 100000) {
			if (!visited[new_loc]) {
				q.push({ cur_times + 1, new_loc });
				if (new_loc != m) visited[new_loc] = 1;
				timing[new_loc] = cur_times + 1;
			}
			else {
				if (timing[new_loc] == cur_times + 1) {
					q.push({ cur_times + 1, new_loc });
				}

			}
		}

		new_loc = cur_loc * 2;
		if (new_loc >= 0 && new_loc <= 100000) {
			if (!visited[new_loc]) {
				q.push({ cur_times + 1, new_loc });
				if (new_loc != m) visited[new_loc] = 1;
				timing[new_loc] = cur_times + 1;
			}
			else {
				if (timing[new_loc] == cur_times + 1) {
					q.push({ cur_times + 1, new_loc });
				}

			}
		}
	}
}

int main() {
	cin >> n >> m;

	q.push({ 0, n });
	visited[n] = 1;

	bfs();

	cout << ans_time << "\n" << ans_cnt;


}