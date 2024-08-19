#include <iostream>
#include <queue>

using namespace std;

int N;
int fruit;
int tang[10];
int answer;
int types;
queue<int> q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> fruit;
        q.push(fruit);

        if (tang[fruit]++ == 0)
        {
            ++types;
        }

        while (types > 2)
        {
            fruit = q.front();
            q.pop();

            if (--tang[fruit] == 0)
            {
                --types;
            }
        }

        answer = max(answer, static_cast<int>(q.size()));
    }

    cout << answer;
    return 0;
}