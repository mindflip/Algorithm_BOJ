#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int t;
int arr[10001];
bool visit[10001];
int ret;

bool bfs(int s, int d) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	visit[s] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (cur == d) {
			ret = depth;
			return true;
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j <= 9; ++j) {
				string temp = to_string(cur);
				// cout << temp << "\n";
				temp[i] = j + '0';
				int next = stoi(temp);
				if (visit[next] || arr[next] == 0 || next < 1000) continue;
				visit[next] = true;
				q.push({ next, depth + 1 });
			}
		}
	}

	return false;
}

int main() {
	// 소수 만들기
	for (int i = 2; i <= 10000; ++i) arr[i] = i;

	for (int i = 2; i <= 10000; ++i) {
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j <= 10000; j += i) arr[j] = 0;
	}
	
	cin >> t;

	int s, d;
	while (t--) {
		cin >> s >> d;

		if (bfs(s, d)) {
			cout << ret << "\n";
		}
		else {
			cout << "Impossible\n";
		}
	}
}