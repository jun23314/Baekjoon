#include <iostream>
#include <string>
#include <queue>

using namespace std;

string a, b;
queue<pair<string, int>> q;

string multi(string str) {
	int num = stoll(str);
	num *= 2;
	return to_string(num);
}

string add(string str) {
	return str + "1";
}


int cal(int str_len) {
	while (!q.empty()) {
		string cur_str = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();

		string new_str = multi(cur_str);
		if (new_str == b) return cur_cnt + 2;
		if (new_str.length() > str_len) continue;

		q.push({ new_str, cur_cnt + 1 });

		new_str = add(cur_str);
		if (new_str == b) return cur_cnt + 2;
		if (new_str.length() > str_len) continue;

		q.push({ new_str, cur_cnt + 1 });
	}
	return -1;
}
int main() {
	cin >> a >> b;

	q.push({ a, 0 });
	
	cout << cal(b.length());

	return 0;
}