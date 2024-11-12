#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str;
        int arr[50] = {0, };
        int com[50];
        cin >> str;
        
        for(int i = 0; i < str.length(); ++i){
            com[i] = str[i] - '0';
        }

        int ans = 0;
        
        if(arr[0] != com[0]) {
            arr[0] = (arr[0] + 1) % 2;
            ans++;
        }
        
        for(int i = 1; i < str.length(); ++i){
            arr[i] = arr[i-1];
            
            if(arr[i] == com[i]) continue;
            arr[i] = (arr[i] + 1) % 2;
            ans++;
        }
        
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}