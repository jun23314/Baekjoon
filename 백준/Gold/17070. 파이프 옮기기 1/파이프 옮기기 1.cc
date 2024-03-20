#include <iostream>
#include <stack>

using namespace std;

typedef struct Pipe {
    int x;
    int y;
    int where;//옆0 아래1 대각2
};

int main() {
    // 4 <= n <= 20
    int n;
    cin >> n;

    int square[20][20];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> square[i][j];
        }
    }

    int cnt = 0;
    stack<Pipe> pipes;
    //옆
    if (square[1][3] == 0) pipes.push({ 1,3,0 });

    //대각
    if (square[1][3] == 0 && square[2][2] == 0 && square[2][3] == 0) pipes.push({ 2, 3, 2 });

    while (1) {
        if (pipes.empty()) break;

        Pipe tmp = pipes.top();
        pipes.pop();

        int cur_x = tmp.x;
        int cur_y = tmp.y;

        if (tmp.where == 0) {//옆
            //옆
            if (cur_y <= n && square[cur_x][cur_y + 1] == 0) { // 네모 안이고 옆칸이 비어있으면
                if (cur_x == n && cur_y + 1 == n) cnt++;
                else if(cur_x <= n && cur_y + 1 <= n) pipes.push({ cur_x, cur_y + 1, 0 }); // 네모 안이면 push
            }
            //대각
            if (cur_x <= n && cur_y <= n && square[cur_x + 1][cur_y + 1] == 0 && square[cur_x + 1][cur_y] == 0 && square[cur_x][cur_y + 1] == 0) {
                if (cur_x + 1 == n && cur_y + 1 == n) cnt++;
                else if(cur_x + 1 <= n && cur_y + 1 <= n) pipes.push({ cur_x + 1, cur_y + 1, 2 });
            }
        }
        else if (tmp.where == 1) {//아래
            //아래
            if (cur_x <= n && square[cur_x + 1][cur_y] == 0) {
                if (cur_x + 1 == n && cur_y == n) cnt++;
                else if (cur_x + 1 <= n && cur_y <= n) pipes.push({ cur_x + 1, cur_y, 1 });
            }
            //대각
            if (cur_x <= n && cur_y <= n && square[cur_x + 1][cur_y + 1] == 0 && square[cur_x + 1][cur_y] == 0 && square[cur_x][cur_y + 1] == 0) {
                if (cur_x + 1 == n && cur_y + 1 == n) cnt++;
                else if (cur_x + 1 <= n && cur_y + 1 <= n) pipes.push({ cur_x + 1, cur_y + 1, 2 });
            }
        }
        else {//대각
            //옆
            if (cur_y <= n && square[cur_x][cur_y + 1] == 0) { // 네모 안이고 옆칸이 비어있으면
                if (cur_x == n && cur_y + 1 == n) cnt++;
                else if (cur_x <= n && cur_y + 1 <= n) pipes.push({ cur_x, cur_y + 1, 0 }); // 네모 안이면 push
            }
            //대각
            if (cur_x <= n && cur_y <= n && square[cur_x + 1][cur_y + 1] == 0 && square[cur_x + 1][cur_y] == 0 && square[cur_x][cur_y + 1] == 0) {
                if (cur_x + 1 == n && cur_y + 1 == n) cnt++;
                else if (cur_x + 1 <= n && cur_y + 1 <= n) pipes.push({ cur_x + 1, cur_y + 1, 2 });
            }
            //아래
            if (cur_x <= n && square[cur_x + 1][cur_y] == 0) {
                if (cur_x + 1 == n && cur_y == n) cnt++;
                else if (cur_x + 1 <= n && cur_y <= n) pipes.push({ cur_x + 1, cur_y, 1 });
            }

        }

    }

    cout << cnt;
    
    return 0;
}
