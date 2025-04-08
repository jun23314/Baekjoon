#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int n, k;
vector<pair<int, int>> homes;
vector<pair<int, int>>::iterator it;
int num[51];
int res[3];
int ans = 987654321;


void calc() {
	int biggest = 0;
	for (it = homes.begin(); it != homes.end(); ++it) {
		int dis = 987654321; // 가장 가까운 대피소와의 거리
		int x = it->first;
		int y = it->second;

		for (int i = 0; i < k; ++i) {
			int idx = res[i]; // 대피소 번호
			int nx = homes[idx].first;
			int ny = homes[idx].second;
			int d = abs(x - nx) + abs(y - ny);
			if (d == 0) {
				dis = 987654321;
				break;
			}
			dis = min(dis, d);
		}

		if (dis == 987654321) continue;
		biggest = max(biggest, dis); // 대피소와의 거리 중 가장 큰 값
	}

	ans = min(ans, biggest);
}

void comb(int start, int idx) {
	if (idx == k) {
		calc();
		return;
	}

	for (int i = start; i < n; ++i) {
		res[idx] = i;
		comb(i+1 , idx+1);
	}
}

int main() {
	cin >> n >> k; // n개 중에 k개 고르기
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		homes.push_back({ x, y });
	}

	comb(0, 0);

	cout << ans;

}
