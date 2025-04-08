#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string s, t;
queue<string> q;

int main() {
	cin >> s >> t;
	
	bool flag = false;

	q.push(t);
	while (!q.empty()) {
		string now = q.front();
		q.pop();

		if (now == s) {
			flag = true;
			break;
		}

		if (now[now.length() - 1] == 'A') {
			string a = now.substr(0, now.length()-1);
			q.push(a);
		}
		
		if (now[0] == 'B') {
			string b = now.substr(1, now.length());
			reverse(b.begin(), b.end());
			q.push(b);
		}
	}

	if (flag) cout << 1;
	else cout << 0;

	return 0;
}