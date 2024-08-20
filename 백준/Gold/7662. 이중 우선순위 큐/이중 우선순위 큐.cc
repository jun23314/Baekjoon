#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int T;
int K;
char cmd;
long long n;

int main() {
	cin >> T;

	for (int i = 0; i < T; ++i) {
		priority_queue<long long, vector<long long>, greater<long long>> minQ;
		priority_queue<long long> maxQ;
		unordered_map<int, int> m;

		cin >> K;
		
		int dataLeng = 0;
		for (int j = 0; j < K; ++j) {
			cin >> cmd >> n;
			if (cmd == 'I') {
				dataLeng++;
				minQ.push(n);
				maxQ.push(n);
				m[n]++;
			}
			else if (cmd == 'D') {
				if (n == 1) {
					if (maxQ.empty()) continue;
					m[maxQ.top()]--;
					maxQ.pop();
				}
				else if (n == -1) {
					if (minQ.empty()) continue;
					m[minQ.top()]--;
					minQ.pop();
				}
				while (!minQ.empty() && m[minQ.top()] == 0) minQ.pop();
				while (!maxQ.empty() && m[maxQ.top()] == 0) maxQ.pop();
			}


		}
		
		if (maxQ.empty() || minQ.empty()) cout << "EMPTY\n";
		else cout << maxQ.top() << " " << minQ.top() << "\n";
	}

	return 0;
}