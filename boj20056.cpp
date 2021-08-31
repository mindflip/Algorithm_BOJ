#include <iostream>
#include <vector>

using namespace std;

struct FB { int x, y, m, s, d; };

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, m, k;
vector<FB> fbs;
vector<int> board[51][51];

void move() {
	vector<int> newBoard[51][51];

	for (int i = 0; i < (int)fbs.size(); ++i) {
		FB cur = fbs[i];
		int d = cur.d;
		int s = cur.s % n;
		int nx = (cur.x + dx[d] * s + n) % n;
		int ny = (cur.y + dy[d] * s + n) % n;
		fbs[i].x = nx;
		fbs[i].y = ny;
		newBoard[nx][ny].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			board[i][j] = newBoard[i][j];
		}
	}
}

void separate() {
	vector<FB> newFbs;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num = (int)board[i][j].size();
			if (num == 0) continue;
			if (num == 1) {
				newFbs.push_back(fbs[board[i][j][0]]);
				continue;
			}

			int sum_m = 0, sum_s = 0;
			bool isOdd = true, isEven = true;
			for (int k = 0; k < (int)board[i][j].size(); ++k) {
				FB cur = fbs[board[i][j][k]];
				sum_m += cur.m;
				sum_s += cur.s;
				if (cur.d % 2 == 0) isOdd = false;
				else isEven = false;
			}

			if (sum_m / 5 == 0) continue;

			int cur_m = sum_m / 5;
			int cur_s = sum_s / num;
			for (int k = 0; k < 4; ++k) {
				if (isOdd || isEven) {
					newFbs.push_back({ i, j, cur_m, cur_s, k * 2 });
				}
				else {
					newFbs.push_back({ i, j, cur_m, cur_s, k * 2 + 1 });
				}
			}
		}
	}

	fbs = newFbs;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		x--; y--;
		fbs.push_back({ x, y, m, s, d });
		board[x][y].push_back(i);
	}


	while (k--) {
		move();
		separate();
	}

	int ret = 0;
	for (const FB &cur : fbs) {
		ret += cur.m;
	}

	cout << ret;
}