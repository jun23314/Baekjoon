#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#define INF 987654321
using namespace std;

int n, ans=INF, cnt=0;
string st, dt, temp;

void lightOn(int idx){
	if(idx>0) temp[idx-1] = (temp[idx-1]=='0') ? '1' : '0';
	temp[idx] = (temp[idx]=='0') ? '1' : '0';
	if(idx<n-1) temp[idx+1] = (temp[idx+1]=='0') ? '1' : '0';
}

void solve(int first){
	temp = st;
	cnt = 0;
	
	if(first==0){
		temp[0] = (temp[0]=='0') ? '1' : '0';
		temp[1] = (temp[1]=='0') ? '1' : '0';
		cnt++;
	}
	
	for(int i=1; i<n; i++){
		if(temp[i-1] != dt[i-1]){
			lightOn(i);
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
	
	if(ans!=INF) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}