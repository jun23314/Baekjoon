#include <iostream>
#include <algorithm>
#define INF 2000000001

using namespace std;

int A[100001] = { 0, };
int direction_i[3] = { 0,1,0 };
int direction_j[3] = { 0,0,-1 };

int cal(int M, int N) {
	int start = 0, end = 0;
	int smaller = INF;

	while (start < N && end < N) {
		int tmp = A[end] - A[start];

		if (tmp == M) return M;

		if (tmp >= M) {
			start++;
			smaller = min(smaller, tmp);
		}
		else if (tmp < M) end++;
	}

	return smaller;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}

	sort(A, A + n);

	printf("%d", cal(m, n));

	return 0;
}