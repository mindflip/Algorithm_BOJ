#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
vector<int> graph[100001];
vector<pair<int, int>> edges;
int parent[100001];
int nsize[100001];
int ret;

void initParent() {
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
		nsize[i] = 1;
	}
}

int getParent(int x) {
	return parent[x] == x ? x : parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x != y) {
		parent[x] = y;
		nsize[y] += nsize[x];
	}
}

int main() {
	cin >> n >> m >> q;
	initParent();

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edges.push_back({ a, b });
	}

	vector<int> dc;

	for (int i = 0; i < q; ++i) {
		cin >> a;
		a--;
		dc.push_back(a);
		edges[a].first *= -1;
	}

	for (int i = 0; i < m; ++i) {
		if (edges[i].first < 0) continue;
		unionParent(edges[i].first, edges[i].second);
	}

	for (int i = dc.size() - 1; i >= 0; --i) {
		int pa = getParent(edges[dc[i]].first * -1);
		int pb = getParent(edges[dc[i]].second);
		if (pa != pb) ret += nsize[pa] * nsize[pb];
		unionParent(pa, pb);
	}

	cout << ret;
}