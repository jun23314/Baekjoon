#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct sett {
	string cc;
	int leng;
};
vector<char> v;
queue<sett> q;
int l, c;

void bfs() {
	while (!q.empty()) {
		sett tmp = q.front();
		q.pop();
		if (tmp.leng == l) {
			int ahdma = 0;
			for (int i = 0; i < l; ++i) {
				if (tmp.cc[i] == 'a' || tmp.cc[i] == 'e' ||
					tmp.cc[i] == 'i' || tmp.cc[i] == 'o' ||
					tmp.cc[i] == 'u') {
					ahdma++;
				}
			}
			if (ahdma >= 1 && l - ahdma >= 2) {
				cout << tmp.cc << "\n";
			}
			continue;
		}

		for (auto k : v) {
			if (tmp.cc[tmp.leng - 1] < k) {
				q.push({ tmp.cc + k, tmp.leng + 1 });
			}
		}

	}
}

int main() {
	cin.tie(0);
	cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; ++i) {
		char cc;
		cin >> cc;
		v.push_back(cc);
	}

	sort(v.begin(), v.end());

	
	for (auto k : v) {
		string ccc = "";
		ccc = k;
		q.push({ ccc, 1});
	}

	bfs();
	
}