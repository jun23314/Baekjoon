#include <iostream>

using namespace std;

int n, m;
int x, y;
int uf[500001] = { 0, };

void initArr() {
	for (int i = 0; i < n; ++i) {
		uf[i] = i;
	}
}

int find(int num) {
	if (num == uf[num]) return num;
	return uf[num] = find(uf[num]);
}

bool unionFind(int start, int end) {
	start = find(start);
	end = find(end);

	if (start == end) return true;
	if (start < end) uf[end] = start;
	else uf[start] = end;
	return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin >> n >> m;

	initArr();
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		if (unionFind(x, y)){
            cout << i;
            return 0;
        }
	}

	cout << "0";
	return 0;
}
