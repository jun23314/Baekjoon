#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int n, m;
unordered_map<string, set<string>> girls;
string groupName;
string name;
int num;
int type;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> groupName;
		cin >> num;

		set<string> s;
		for (int j = 0; j < num; ++j) {
			cin >> name;
			s.insert(name);
		}

		girls[groupName] = s;
	}

	for (int i = 1; i <= m; ++i) {
		cin >> name;
		cin >> type;
		if (type == 0) {
			for (auto j : girls.find(name)->second) cout << j << "\n";
		}
		else if (type == 1) {
			for (auto j : girls) {
				if (j.second.find(name) != j.second.end()) {
					cout << j.first << "\n";
					break;
				}
			}

		}
	}

	return 0;
}