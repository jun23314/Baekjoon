#include<iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    int score, kal, idx;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, L;
        cin >> N >> L;
        
        int score[20];
        int kal[20];
        for(int i = 0; i < N; ++i) cin >> score[i] >> kal[i];
        
        queue<Node> q;
        q.push({0, 0, -1});
        for(int i = 0; i < N; ++i){
            while(1){
                Node tmp = q.front();
                if(tmp.idx == i) break;
                q.pop();
                
                q.push({tmp.score, tmp.kal, i});
                if(tmp.kal + kal[i] <= L) q.push({tmp.score + score[i], tmp.kal + kal[i], i});
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            Node tmp = q.front();
            q.pop();
            ans = max(ans, tmp.score);
        }
        
        cout << "#" << test_case << " " << ans << "\n";
        
        
        

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}