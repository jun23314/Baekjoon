#include<iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int tc;
        cin >> tc;
        
        int arr[101][101] = {0, };
        for(int i = 1; i <= 100; ++i)
            for(int j = 1; j <= 100; ++j)
                cin >> arr[i][j];
        
        int ans = 0;
        
        int diagonal_sum = 0;
        int row_max = 0;
         for(int i = 1; i <= 100; ++i){
             int row_sum = 0;
            for(int j = 1; j <= 100; ++j){
                if(i == j) diagonal_sum += arr[i][j];
                
                row_sum += arr[i][j];
            }
             row_max = max(row_max, row_sum);
         }
        
        ans = max(row_max, diagonal_sum);
        
        int col_max = 0;
         for(int j = 1; j <= 100; ++j){
             int col_sum = 0;
            for(int i = 1; i <= 100; ++i){
                col_sum += arr[i][j];
            }
             col_max = max(col_max, col_sum);
         }
        
        ans = max(ans, col_max);
        
        int num = 100;
        diagonal_sum = 0;
        for(int i = 0; i <= 100; ++i){
            diagonal_sum += arr[i][num];
            num--;
        }
        
        ans = max(ans, diagonal_sum);
        
        cout << "#" << tc << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}