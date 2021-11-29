#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, m;
int board[1001][1001];
bool visit[1001][1001];
int clusterNumber = 1;
map<int, int> clusterSize;

void dfs(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || board[nx][ny] == 0) continue;
		visit[nx][ny] = true;
		board[nx][ny] = clusterNumber;
		clusterSize[clusterNumber]++;
		dfs(nx, ny);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0 || visit[i][j]) continue;
			visit[i][j] = true;
			board[i][j] = clusterNumber;
			clusterSize[clusterNumber]++;
			dfs(i, j);
			clusterNumber++;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visit[i][j]) continue;
			set<int> temp;
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
				temp.insert(board[nx][ny]);
			}

			int sum = 0;
			for (auto it = temp.begin(); it != temp.end(); ++it) {
				sum += clusterSize[*it];
			}

			ret = max(ret, sum + 1);
		}
	}

	cout << ret;
}