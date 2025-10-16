#include <iostream>
#include <algorithm>

#define INF 2000000001

using namespace std;

int n;
pair<int, int> p;
int ans = 0;
int water[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> water[i];
	sort(water, water + n);

	ans = INF;
	int l = 0, r = n - 1;
	while (l < r) {
		int tmp = water[l] + water[r];

		if (abs(tmp) < ans) { // 유효한 값 도출
			ans = abs(tmp);
			p = make_pair(water[l], water[r]);
			if (ans == 0) break;
		}

		if (tmp < 0) l++;
		else r--;
	}

	cout << p.first << " " << p.second;
}