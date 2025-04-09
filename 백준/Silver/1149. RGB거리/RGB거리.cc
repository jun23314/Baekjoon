#include <algorithm>
#include <iostream>

using namespace std;

int dp[1005][3];

int main() {
	int n;
	int ans;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &dp[i][j]);

	for (int i = 1; i < n; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}

	ans = min({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] });

	cout << ans;

	return 0;
}