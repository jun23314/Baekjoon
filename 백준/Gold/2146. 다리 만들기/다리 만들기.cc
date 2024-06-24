#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, res = 987654321;
int A[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool visit[101][101];

void findLand(int i, int j, int count) {
    queue<pair<int, int>> q;

    A[i][j] = count;
    q.push({ i,j });

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (A[ny][nx] == 0 || A[ny][nx] == count) continue;

            q.push({ ny,nx });

            A[ny][nx] = count;
        }
    }
}

void bfs(int num) {
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == num) {
                visit[i][j] = true;
                q.push({ {i,j},0 });
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int n = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (A[ny][nx] != 0 && A[ny][nx] != num) {
                res = min(res, n);
                return;
            }
            if (visit[ny][nx]) continue;

            visit[ny][nx] = true;
            q.push({ {ny,nx},n + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int count = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 1) {
                findLand(i, j, count);
                count++;
            }
        }
    }

    for (int i = 2; i < count; i++) {
        memset(visit, false, sizeof(visit));
        bfs(i);
    }

    cout << res;

    return 0;
}