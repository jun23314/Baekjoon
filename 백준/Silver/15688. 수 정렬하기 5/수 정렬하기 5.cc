#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> v;
int n;
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

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		cout << v[i] << "\n";
	}

	return 0;
}