#include <iostream>
#include <vector>
#include <set>

using namespace std;

int a, b;
int num;
vector<int> input;
vector<vector<int>::iterator> part;
set<vector<vector<int>::iterator>> s;
set<vector<int>> res;

void printing() {
	for (auto i : res) {
		for (auto k : i)
			cout << k << " ";
		cout << "\n";
	}
}

void numbers() {
	if (part.size() == b) {
		s.insert(part);
		return;
	}

	for (auto it = input.begin(); it != input.end(); ++it) {
		bool flag = 0;
		for (auto k : part) {
			if (it == k) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		part.push_back(it);
		numbers();
		part.pop_back();
	}

	return;
}

int main() {
	cin >> a >> b;

	for (int i = 1; i <= a; ++i) {
		cin >> num;
		input.push_back(num);
	}

	numbers();

	for (auto i : s) {
		vector<int> tmp;
		for (auto j : i) {
			tmp.push_back(*j);
		}
		res.insert(tmp);
	}

	printing();

	return 0;
}
