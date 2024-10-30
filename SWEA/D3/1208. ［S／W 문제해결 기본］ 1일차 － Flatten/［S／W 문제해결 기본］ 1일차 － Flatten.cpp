#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int dump;
        cin >> dump;
        
        vector<int> arr;
        for(int i = 0; i < 100; ++i){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < dump; ++i){
            int endest = *arr.rbegin();
            arr.pop_back();
            arr.push_back(endest-1);
            
            int frontest = *arr.begin();
            arr.erase(arr.begin());
            arr.push_back(frontest+1);
            
            sort(arr.begin(), arr.end());
        }
        
        int ans = *arr.rbegin() - *arr.begin();
        
       cout << "#" << test_case << " "  << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}