#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BOOK {
	int price;
	string title;
};

string str;
int cnt[26];
int sCnt[26];
int n;
vector<BOOK> books;
int ret = 987654321;

bool isValid() {
	for (int i = 0; i < 26; ++i)
		if (cnt[i] > sCnt[i]) return false;
	return true;
}

void dfs(int idx, int sum) {
	if (idx == n) {
		if (isValid())
			ret = min(ret, sum);
		return;
	}

	BOOK cur = books[idx];

	for (int i = 0; i < cur.title.length(); ++i) {
		sCnt[cur.title[i] - 'A']++;
	}
	dfs(idx + 1, sum + cur.price);
	for (int i = 0; i < cur.title.length(); ++i) {
		sCnt[cur.title[i] - 'A']--;
	}
	dfs(idx + 1, sum);
}

int main() {
	cin >> str >> n;
	for (int i = 0; i < str.length(); ++i) {
		cnt[str[i] - 'A']++;
	}

	for (int i = 0; i < n; ++i) {
		BOOK a;
		cin >> a.price >> a.title;
		books.push_back(a);
	}

	dfs(0, 0);

	cout << (ret == 987654321 ? -1 : ret);
}