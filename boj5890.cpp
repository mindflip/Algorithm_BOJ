#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;

typedef pair<int, pair<int, int>> pii;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, tx, ty;
int board[1001][1001];
int dist[1001][1001];
int ret;

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			dist[i][j] = MAX;
		}
	}
	pq.push({ 0, { tx, ty } });
	dist[tx][ty] = 0;

	while (!pq.empty()) {
		pair<int,int> cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur.first][cur.second] < cost) continue;

		for (int d = 0; d < 4; ++d) {
			int nx = cur.first + dx[d];
			int ny = cur.second + dy[d];
			if (nx < 0 || nx > 1000 || ny < 0 || ny > 1000) {
				ret = cost;
				return;
			}
			int nCost = board[nx][ny];

			if (dist[nx][ny] <= dist[cur.first][cur.second] + nCost) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + nCost;
			pq.push({ dist[nx][ny], {nx, ny} });
		}
	}
}

int main() {
	cin >> n >> tx >> ty;
	int a, b;
	
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		board[a][b] = 1;
	}

	dijkstra();

	cout << ret;
}