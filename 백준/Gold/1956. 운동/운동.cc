#include <iostream>
#define INF 4000001

using namespace std;

int mini[402][402];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    for (int i = 0; i <= V; ++i) {
        for (int j = 0; j <= V; ++j) {
            mini[i][j] = INF;
        }
    }

    for (int i = 0; i < E; ++i) {
        int s, e, v;
        cin >> s >> e >> v;
        mini[s][e] = v;
    }

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            for (int k = 1; k <= V; ++k) {
                if (mini[j][k] > mini[j][i] + mini[i][k])
                    mini[j][k] = mini[j][i] + mini[i][k];
            }
        }
    }

    int min = INF;
    for (int i = 1; i <= V; ++i) {
        if (mini[i][i] < min) min = mini[i][i];
    }

    if (min < INF) cout << min;
    else cout << -1;

    return 0;
}
