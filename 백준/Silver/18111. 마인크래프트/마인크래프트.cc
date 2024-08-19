#include <iostream>
#include <map>
#define BLOCK_REMOVE_TIMES 2
#define BLOCK_INSERT_TIMES 1
#define MAX_BLOCK_SIZE 256

using namespace std;

int N, M;
int B;
int arr[501][501] = { 0, };
map<int, int> m;

int main() {
	cin >> N >> M >> B;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			m[arr[i][j]]++;
		}
	}

	int times = 0;

	while (1) {
		if (m.size() == 1) {
			cout << times << " " << m.begin()->first;
			return 0;
		}

		int max_height = m.rbegin()->first;
		int max_cnt = m.rbegin()->second;
		int min_height = m.begin()->first;
		int min_cnt = m.begin()->second;

		if (min_cnt > B) {
			//제거 필요
			m[max_height - 1] += max_cnt;
			B += max_cnt;
			times = times + max_cnt * BLOCK_REMOVE_TIMES;
			m.erase(max_height);
			continue;
		}

		if (2 * max_cnt >= min_cnt) {
			//채우기 필요
			m[min_height + 1] += min_cnt;
			B -= min_cnt;
			times = times + min_cnt * BLOCK_INSERT_TIMES;
			m.erase(min_height);
		}
		else {
			//제거 필요
			m[max_height - 1] += max_cnt;
			B += max_cnt;
			times = times + max_cnt * BLOCK_REMOVE_TIMES;
			m.erase(max_height);
		}
	}

	return 0;
}
