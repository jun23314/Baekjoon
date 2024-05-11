#include <iostream>

using namespace std;

int boxs[1001] = { 0, };
int ans[1001] = { 1, };
int solve(int n) {
	for (int i = 1; i < n; ++i) {
		int now_box = boxs[i];
		int tmp_max = -1;
		int max_idx = -1;

		for (int j = i - 1; j >= 0; --j) {
			if (boxs[j] < now_box) {
				if (tmp_max < ans[j]) {
					tmp_max = ans[j];
					max_idx = j;
				}
			}
		}
		
		if (max_idx == -1) ans[i] = 1;
		else ans[i] = ans[max_idx] + 1;
	}

	int final_max = -1;
	for (int i = 1; i < n; ++i)
		if (ans[i] > final_max) final_max = ans[i];


	return final_max;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &boxs[i]);
	}

	printf("%d", solve(n));

	return 0;
}