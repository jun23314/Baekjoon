#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, m; string str;
	cin >> n >> m >> str;

	//문제 해결
	int ans = 0;
	for (int i = 0; i < m; i++) {
		
		int k = 0; //IOI의 개수
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;

			if (k == n) {
				ans++;
				k--; //오른쪽으로 +2만큼 이동할텐데 이때 k값이 바뀌지 않게 하나 빼줌
			}
			i += 2; //인덱스 뛰어 넘기
		}
	}

	//결과 출력
	cout << ans << '\n';

}