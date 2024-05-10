#include <iostream>

using namespace std;

int ans[1005][1005] = { 0, };
int main() {
	int n, k;
	cin >> n >> k;

	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (j == 1) ans[i][j] = i;
			else if (i > 2 && i < n)
				ans[i][j] = (ans[i - 2][j - 1] + ans[i - 1][j]) % 1000000003;
			else if (i == n)
				ans[i][j] = (ans[i - 3][j - 1]+ ans[i - 1][j]) % 1000000003;
		}
	}

	cout << ans[n][k] % 1000000003;
	return 0;
}