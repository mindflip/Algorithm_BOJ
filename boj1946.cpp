#include <iostream>

using namespace std;

int tc;

int main() {
	cin >> tc;

	while (tc--) {
		int n;
		int idx;
		int arr[100001] = { 0 , };
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> idx;
			cin >> arr[idx];
		}

		int candi = arr[1];
		int ret = 1;
		for (int i = 2; i <= n; ++i) {
			if (candi > arr[i]) {
				candi = arr[i];
				ret++;
			}
		}

		cout << ret << "\n";
	}
}