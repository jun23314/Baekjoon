#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;
string bomb;
stack<char> str;

int main() {
	cin >> input;
	cin >> bomb;

	int bombleng = bomb.length();
	int inputleng = input.length();
	char last = bomb[bombleng - 1];

	for (int i = 0; i < inputleng; ++i) {
		str.push(input[i]);

		if(input[i] == last) { // 확인 필요
			if (str.size() < bombleng) continue;

			string a;
			for (int j = 0; j < bombleng; ++j) {
				a.push_back(str.top());
				str.pop();
			}

			reverse(a.begin(), a.end());
			if (a == bomb) continue;

			for (int j = 0; j < bombleng; ++j) {
				str.push(a[j]);
			}
		}
	}

	if(str.empty()) cout << "FRULA";
	else {
		string a;
		while (!str.empty()) {
			a.push_back(str.top());
			str.pop();
		}
		reverse(a.begin(), a.end());
		cout << a;
	}
}