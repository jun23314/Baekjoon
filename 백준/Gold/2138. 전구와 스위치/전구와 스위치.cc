#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, ans=100006;
string st, dt, temp;

void solve(int first){
	temp = st;
	int cnt = 0;
	
	if(first==0){
		temp[0] = (temp[0]=='0') ? '1' : '0';
		temp[1] = (temp[1]=='0') ? '1' : '0';
		cnt++;
	}
	
	for(int i=1; i<n; i++){
		if(temp[i-1] != dt[i-1]){
			temp[i-1] = (temp[i-1]=='0') ? '1' : '0';
	        temp[i] = (temp[i]=='0') ? '1' : '0';
	        if(i<n-1) temp[i+1] = (temp[i+1]=='0') ? '1' : '0';
			cnt++;
		}
	}
	
	if(temp==dt) ans = min(ans, cnt);
}


int main(){
	cin >> n;
	cin >> st >> dt;
	
	solve(0);
	solve(1);
	
	if(ans!=100006) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}