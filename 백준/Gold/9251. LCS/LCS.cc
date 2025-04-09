#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int lcs[1001][1001] = { 0, };

int main() {
	string a;
	string b;

	cin >> a >> b;
	
	int alen = a.length();
	int blen = b.length();

	for (int i = 1; i <= alen; ++i) {
		for (int j = 1; j <= blen; ++j) {
			if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[alen][blen];

	return 0;
}