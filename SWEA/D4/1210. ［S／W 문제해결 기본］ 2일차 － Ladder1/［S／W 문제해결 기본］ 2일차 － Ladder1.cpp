#include<iostream>

using namespace std;

int ladder[101][101] = { 0, };
int dy[3] = { -1, 1 };

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> test_case;

		int start_x, start_y;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> ladder[i][j];

				if (ladder[i][j] == 2) {
					start_x = i;
					start_y = j;
				}
			}
		}

		while (1) {
			if (start_x == 0) break;

			for (int i = 0; i < 2; ++i) {
				int new_y = start_y + dy[i];
				if (new_y < 0 || new_y > 99) continue;

				if (ladder[start_x][new_y] == 0) continue;

				start_y = new_y;
				while (1) {
					int new_y = start_y + dy[i];
					if (new_y < 0 || new_y > 99) break;

					if (ladder[start_x][new_y] == 0) break;
					start_y = new_y;
				}

				break;
			}

			start_x--;
		}


		cout << "#" << test_case << " " << start_y << "\n";
	}
	return 0;
}