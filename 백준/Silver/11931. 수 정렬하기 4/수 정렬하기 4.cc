#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> v;
int n, m;
int num[51];
int cnt = 0;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; ++i) {
		cout << v[i] << "\n";
	}

	return 0;
}