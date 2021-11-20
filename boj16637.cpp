#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;
int ret;

int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
}

void dfs(int depth, int val) {
	if (depth >= n) {
		ret = max(ret, val);
		return;
	}

	char op = (depth == 0) ? '+' : s[depth - 1];
	int nextVal = cal(val, s[depth] - '0', op);

	// ���� �Ͱ� �ٷ� ����
	dfs(depth + 2, nextVal);

	// ���� �Ͱ� ���� �� ���� �Ͱ� ����
	if (depth + 2 < n) {
		nextVal = cal(s[depth] - '0', s[depth + 2] - '0', s[depth + 1]);
		nextVal = cal(val, nextVal, op);
		dfs(depth + 4, nextVal);
	}
}

int main() {
	cin >> n >> s;

	dfs(0, 0);

	cout << ret;
}