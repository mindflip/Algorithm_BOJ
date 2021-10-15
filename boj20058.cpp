#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct POS {
	int x, y;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, q, m;
int board[65][65];
int temp[65][65];
bool visit[65][65];
int cluster;

void printMap() {
	cout << "@@@@\n";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
void rotate(int l) {
	int s = pow(2, l);

	int i = 0, j = 0;
	for (int i = 0; i < m; i += s) {
		for (int j = 0; j < m; j += s) {
			for (int x = i; x < i + s; ++x) {
				for (int y = j; y < j + s; ++y) {
					temp[x][y] = board[i + j + s - 1 - y][j + i + x];
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			board[i][j] = temp[i][j];
		}
	}

	printMap();
}
*/

void rotate(int x, int y, int s) {
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			temp[j][s - 1 - i] = board[x + i][y + j];
		}
	}

	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			board[x + i][y + j] = temp[i][j];
		}
	}
}

void storm() {
	int temp[65][65] = { 0, };

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) continue;
			int adj = 0;
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || nx >= m || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
				adj++;
			}
			if (adj >= 3) {
				temp[i][j] = board[i][j];
			}
			else {
				temp[i][j] = board[i][j] - 1;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			board[i][j] = temp[i][j];
		}
	}

	// printMap();
}

int bfs(POS start) {
	queue<POS> q;
	q.push(start);
	
	int sum = 1;

	while (!q.empty()) {
		POS cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= m || visit[nx][ny] || board[nx][ny] == 0) continue;
			visit[nx][ny] = true;
			sum++;
			q.push({ nx, ny });
		}
	}

	return sum;
}

int sum() {
	int ret = 0;
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			ret += board[i][j];
		}
	}

	return ret;
}

int main() {
	cin >> n >> q;
	m = pow(2, n);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	int l;
	for (int i = 0; i < q; ++i) {
		cin >> l;
		int s = 1 << l;
		for (int i = 0; i < m; i += s) {
			for (int j = 0; j < m; j += s) {
				rotate(i, j, s);
			}
		}
		storm();
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visit[i][j] || board[i][j] == 0) continue;
			visit[i][j] = true;
			cluster = max(cluster, bfs({ i, j }));
		}
	}

	cout << sum() << "\n";
	cout << cluster;
}