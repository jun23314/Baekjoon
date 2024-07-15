#include <iostream>
#include <queue>

using namespace std;

int t, w, h;
string arr;
queue<pair<int, int>> q;
queue<pair<int, int>> fire;
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };
char building[1001][1001];

void MoveFire()
{
	int cnt = fire.size();
	for (int i = 0; i < cnt; i++)
	{
		pair<int, int> cur = fire.front();
		fire.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (building[ny][nx] != '.')
				continue;

			building[ny][nx] = '*';
			fire.push({ ny, nx });
		}
	}
}

int MoveS()
{
	int time = 0;
	while (!q.empty())
	{
		time++;
		MoveFire();

		int cnt = q.size();
		for (int i = 0; i < cnt; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					return time;

				if (building[ny][nx] != '.')
					continue;

				building[ny][nx] = '@';
				q.push({ ny, nx });
			}
		}
	}

	return -1;
}

void Reset(int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			building[y][x] = '.';
		}
	}
	while (!q.empty())
		q.pop();
	while (!fire.empty())
		fire.pop();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> building[y][x];

				if (building[y][x] == '@')
					q.push({ y, x });
				else if (building[y][x] == '*')
					fire.push({ y, x });
			}
		}
		int time = MoveS();
		if (time == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << time << endl;

		Reset(w, h);

	}

	return 0;
}