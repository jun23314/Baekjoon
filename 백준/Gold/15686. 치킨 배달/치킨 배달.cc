#include <iostream>
#include <math.h>

using namespace std;

struct Node {
	int x, y;
}chicken[14], home[101];

int N, M;
int nums[14];
int com[14];
int idxH = 1, idxC = 1;
int ans = 987654321;

void comb(int start, int idx) {
	if (idx == M) {

		int sum = 0;
		for (int i = 1; i < idxH; ++i) { // 각 집을 비교
			int minDist = 987654321;
			for (int j = 0; j < idx; ++j) { // 각 치킨집과의 거리 중 작은거 찾기
				int chick = com[j];
				int dist = abs(home[i].x - chicken[chick].x) + abs(home[i].y - chicken[chick].y);
				minDist = min(minDist, dist);
			}

			sum += minDist;
		}

		ans = min(ans, sum);
		return;
	}

	for (int i = start; i < idxC; ++i) {
		com[idx] = nums[i];
		comb(i + 1, idx + 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int num;
			cin >> num;
			if (num == 0) continue;

			if (num == 1) home[idxH++] = { i,j };
			else chicken[idxC++] = { i, j };
		}
	}

	for (int i = 1; i < idxC; ++i) {
		nums[i] = i;
	}

	comb(1, 0);

	cout << ans;
}