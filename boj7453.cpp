#include <iostream>
#include <vector>
#include <algorithm>
#define MM 4005

using namespace std;

int n;
int a[MM], b[MM], c[MM], d[MM];
vector<int> e, f;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			e.push_back(a[i] + b[j]);
			f.push_back(c[i] + d[j]);
		}
	}

	sort(e.begin(), e.end());
	sort(f.begin(), f.end());

	long long ret = 0;

	for (int i = 0; i < n * n; ++i) {
		int left = upper_bound(f.begin(), f.end(), -e[i] - 1) - f.begin();
		int right = upper_bound(f.begin(), f.end(), -e[i]) - f.begin();
		ret += right - left;
	}

	cout << ret;
}