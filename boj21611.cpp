#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct POS {
	int x, y;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
int board[50][50];
int ret;

void printMap() {
	cout << "@@@@@@@\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void removeBalls(int d, int s) {
	int x = n / 2;
	int y = n / 2;
	for (int i = 0; i < s; ++i) {
		x += dx[d];
		y += dy[d];
		board[x][y] = 0;
	}
}

int cd(int d) {
	if (d == 2) return 1;
	if (d == 1) return 3;
	if (d == 3) return 0;
	if (d == 0) return 2;
}

void moveBalls() {
	int x = n / 2;
	int y = n / 2;

	queue<int> temp;

	int rep = 1;
	int d = 2;
	while (y >= 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < rep; ++j) {
				x += dx[d];
				y += dy[d];
				if (y < 0) break;
				if (board[x][y] == 0) continue;
				// ºó Ä­ÀÌ ¾Æ´Ò ¶§ temp¿¡ ¸ðµÎ ´ã±â
				temp.push(board[x][y]);
			}
			if (y < 0) break;
			d = cd(d);
		}
		rep++;
	}

	x = n / 2;
	y = n / 2;
	rep = 1;
	d = 2;
	while (y >= 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < rep; ++j) {
				x += dx[d];
				y += dy[d];
				if (y < 0) break;
				if (!temp.empty()) {
					board[x][y] = temp.front();
					temp.pop();
				}
				else board[x][y] = 0;
			}
			if (y < 0) break;
			d = cd(d);
		}
		rep++;
	}
}

bool bomb() {
	bool isBomb = false;
	vector<POS> candi;

	int x = n / 2;
	int y = n / 2;

	int rep = 1;
	int d = 2;
	int prev = 0;
	while (y >= 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < rep; ++j) {
				x += dx[d];
				y += dy[d];
				if (y < 0) break;
				if (board[x][y] != prev) {
					if (candi.size() >= 4) {
						isBomb = true;
						// ±¸½½ Æø¹ß
						int weight = 0;
						for (POS el : candi) {
							weight = board[el.x][el.y];
							board[el.x][el.y] = 0;
						}
						ret += weight * candi.size();
					}
					prev = board[x][y];
					candi.clear();
					candi.push_back({ x, y });
				}
				else {
					candi.push_back({ x, y });
				}
			}
			if (y < 0) break;
			d = cd(d);
		}
		rep++;
	}

	return isBomb;
}

void makeGroup() {
	vector<int> group;
	vector<int> temp;
	int x = n / 2;
	int y = n / 2;

	int rep = 1;
	int d = 2;
	int prev = 0;
	while (y >= 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < rep; ++j) {
				x += dx[d];
				y += dy[d];
				if (y < 0) break;
				if (board[x][y] != prev) {
					if (prev == 0) {
						prev = board[x][y];
						temp.push_back(board[x][y]);
						continue;
					}
					group.push_back(temp.size());
					group.push_back(temp[0]);
					prev = board[x][y];
					temp.clear();
					temp.push_back(board[x][y]);
				}
				else {
					temp.push_back(board[x][y]);
				}
			}
			if (y < 0) break;
			d = cd(d);
		}
		rep++;
	}

	x = n / 2;
	y = n / 2;
	rep = 1;
	d = 2;
	while (y >= 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < rep; ++j) {
				x += dx[d];
				y += dy[d];
				if (y < 0) break;
				if (!group.empty()) {
					board[x][y] = group.front();
					group.erase(group.begin());
				}
				else board[x][y] = 0;
			}
			if (y < 0) break;
			d = cd(d);
		}
		rep++;
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	int d, s;
	for (int i = 0; i < m; ++i) {
		cin >> d >> s;
		d--;
		removeBalls(d, s);
		moveBalls();
		while (bomb()) {
			moveBalls();
		}
		makeGroup();
	}

	cout << ret;
}