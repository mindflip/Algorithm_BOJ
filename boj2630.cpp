#include <iostream>

using namespace std;

int n;
int board[129][129];
int wCnt, bCnt;

void divide(int r, int c, int n) {
	int tCnt = 0;
	for (int i = r; i < r + n; ++i) {
		for (int j = c; j < c + n; ++j) {
			if (board[i][j]) tCnt++;
		}
	}

	if (tCnt == 0) wCnt++;
	else if (tCnt == n * n) bCnt++;
	else {
		divide(r, c, n / 2);
		divide(r + n / 2, c, n / 2);
		divide(r, c + n / 2, n / 2);
		divide(r + n / 2, c + n / 2, n / 2);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	divide(0, 0, n);

	cout << wCnt << "\n" << bCnt;
}