#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> back;
priority_queue<int> front;
int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);

		if (i == 0) {
			front.push(num);
			printf("%d\n", num);
			continue;
		}

		if (front.size() == back.size()) front.push(num);
		else back.push(num);

		if (!back.empty() && !front.empty()) {
			if (front.top() > back.top()) {
				int tmp = back.top();
				back.pop();
				back.push(front.top());
				front.pop();
				front.push(tmp);
			}
		}
		printf("%d\n", front.top());

	}

	return 0;
}