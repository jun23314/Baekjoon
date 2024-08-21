#include <iostream>
#include <queue>

using namespace std;

struct Node {
	string cmd;
	int number;
};

int A, B;
int T;
int visited[100001] = { 0, };

string bfs() {
	queue<Node> q;
	q.push({ "", A });
	visited[A] = 1;

	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();

		int cur_num = tmp.number;
		string cur_cmd = tmp.cmd;
		if (cur_num == B) return cur_cmd;

		int new_num = cur_num * 2 % 10000;
		if (!visited[new_num]) {
			q.push({ cur_cmd + 'D', new_num });
			visited[new_num] = 1;
		}

		new_num = cur_num - 1;
		if (new_num == -1) new_num = 9999;
		if (!visited[new_num]) {
			q.push({ cur_cmd + 'S', new_num });
			visited[new_num] = 1;
		}

		new_num = cur_num * 10 % 10000 + cur_num / 1000;
		if (!visited[new_num]) {
			q.push({ cur_cmd + 'L', new_num });
			visited[new_num] = 1;
		}

		new_num = cur_num / 10 + cur_num % 10 * 1000;
		if (!visited[new_num]) {
			q.push({ cur_cmd + 'R', new_num });
			visited[new_num] = 1;
		}

	}
	return "??";
}


void initArr() {
	for (int i = 0; i < 100001; ++i) visited[i] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		initArr();
		cin >> A >> B;
		cout << bfs() << "\n";
	}

	return 0;
}