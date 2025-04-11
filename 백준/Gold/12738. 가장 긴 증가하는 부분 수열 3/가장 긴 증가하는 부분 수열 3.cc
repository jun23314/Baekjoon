#include <iostream>
#include <vector>

using namespace std;

int A;
int arr[1000001];
vector<int> ans;

int binarySearch(int target) {
	int left = 0, right = ans.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (ans[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}


int main() {
	cin >> A;
	for (int i = 0; i < A; ++i) {
		cin >> arr[i];
	}

	ans.push_back(arr[0]);
	for (int i = 1; i < A; ++i) {
		if (ans.back() < arr[i])ans.push_back(arr[i]);
		else {
			ans[binarySearch(arr[i])] = arr[i];
		}
	}

	cout << ans.size();
}