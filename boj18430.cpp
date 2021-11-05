#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct POS { int x, y; };

int n, m;
int board[5][5];
int ret;
bool visit[5][5];

int boo[4][2][2] = {
	{
		{1, 2},
		{0, 1}
	},
	{
		{0, 1},
		{1, 2}
	},
	{
		{1, 0},
		{2, 1}
	},
	{
		{2, 1},
		{1, 0}
	}
};

void dfs(int i, int j, int sum) {
	if (j == m - 1) {
		i++;
		j = 0;
	}

	if (i >= n - 1) {
		ret = max(ret, sum);
		return;
	}

	for (int k = 0; k < 4; ++k) {
		bool isValid = true;
		vector<POS> temp;
		int triSum = 0;
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				int nx = i + x;
				int ny = j + y;
				if (boo[k][x][y] == 0) continue;
				if (visit[nx][ny] || nx >= n || ny >=  m) {
					isValid = false;
					break;
				}
				triSum += board[nx][ny] * boo[k][x][y];
				temp.push_back({ nx, ny });
			}
			if (!isValid) break;
		}
		if (!isValid) continue;
		for (POS el : temp) visit[el.x][el.y] = true;
		dfs(i, j + 1, sum + triSum);
		for (POS el : temp) visit[el.x][el.y] = false;
	}


	dfs(i, j + 1, sum);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0);
	cout << ret << "\n";
}