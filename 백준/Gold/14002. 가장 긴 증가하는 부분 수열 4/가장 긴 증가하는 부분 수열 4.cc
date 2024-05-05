#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> dp(N, 1); // dp[i]는 A[i]를 마지막으로 하는 증가하는 부분 수열의 최대 길이를 저장

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = *max_element(dp.begin(), dp.end()); // 가장 긴 증가하는 부분 수열의 길이

    cout << max_length << endl;

    vector<int> result;
    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    result.push_back(A[idx]);
    int prev_length = max_length - 1;

    for (int i = idx - 1; i >= 0; --i) {
        if (dp[i] == prev_length && A[i] < result.back()) {
            result.push_back(A[i]);
            --prev_length;
        }
    }

    reverse(result.begin(), result.end());

    for (auto num : result) {
        cout << num << ' ';
    }

    return 0;
}
