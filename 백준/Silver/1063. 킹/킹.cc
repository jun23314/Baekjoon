#include <iostream>

using namespace std;

int board[55][55] = { 0, };
string moving[8] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };
int x[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int y[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	string king, stone;
	int n;
	cin >> king >> stone >> n;

	int king_x = king[1] - '0';
	int king_y = king[0] - 'A' + 1;
	int stone_x = stone[1] - '0';
	int stone_y = stone[0] - 'A' + 1;

	for (int i = 0; i < n; ++i) {
		string move;
		cin >> move;

		for (int j = 0; j < 8; ++j) {
			if (moving[j] != move) continue;

			int tmp_king_x = king_x + x[j];
			int tmp_king_y = king_y + y[j];
			if (tmp_king_x < 1 || tmp_king_x > 8 || tmp_king_y < 1 || tmp_king_y > 8) continue;

			if (tmp_king_x == stone_x && tmp_king_y == stone_y) {
				int tmp_stone_x = stone_x + x[j];
				int tmp_stone_y = stone_y + y[j];
				if (tmp_stone_x < 1 || tmp_stone_x > 8 || tmp_stone_y < 1 || tmp_stone_y > 8) continue;
				stone_x = tmp_stone_x;
				stone_y = tmp_stone_y;
			}

			king_x = tmp_king_x;
			king_y = tmp_king_y;
		}
	}

	char kingy = king_y + 'A' - 1;
	char stoney = stone_y + 'A' - 1;


	cout << kingy << king_x << "\n" << stoney << stone_x;
}