#include <cstdio>

using namespace std;

int board[12], ans;

int main(){
  int n, s, r;
  scanf("%d %d %d", &n, &s, &r);

  for(int i = 1; i <= n; i++) {
    board[i] = 1;
  }

  for(int i = 0; i < s; i++) {
    int k;
    scanf("%d", &k);
    board[k]--;
  }

  for(int i = 0; i < r; i++) {
    int k;
    scanf("%d", &k);
    board[k]++;
  }

  for(int i = 1; i <= n; i++) {
    if(board[i] == 2){
      if(!board[i-1]) board[i] = board[i-1] = 1;
      else if(!board[i+1]) board[i] = board[i+1] = 1;
    }
  }

  for(int i = 1; i <= n; i++)
    if(!board[i])
      ans++;

  printf("%d", ans);
}