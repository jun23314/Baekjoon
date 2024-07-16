#include <iostream>
#include <set>

using namespace std;

int a, b;
set<int> v;
set<int> part;

void printing() {
	for (auto i : part) cout << i << " ";
	cout << "\n";
}

void numbers(set<int>::iterator now_idx) {
	if (part.size() == b) {
		printing();
		return;
	}

	for (auto it = now_idx; it != v.end(); ++it) {
		part.insert(*it);
		numbers(next(it));
		part.erase(*it);
	}

	return;
}

int main() {
	cin >> a >> b;

	for (int i = 1; i <= a; ++i) v.insert(i);

	numbers(v.begin());

	return 0;
}