#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> result;
vector<int> standard;

vector<int> mix(vector<int> temp, int k) {
	if (k == -1) return temp;

	vector<int> v;

	for (int i = temp.size() - (1 << k); i < temp.size(); ++i) {
		v.push_back(temp[i]);
	}

	v = mix(v, k - 1);

	for (int i = 0; i < temp.size() - (1 << k); ++i) {
		v.push_back(temp[i]);
	}

	return v;
}

int main() {
	cin >> n;
	int c;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		result.push_back(c);
	}

	for (int i = 1; i <= n; ++i) {
		standard.push_back(i);
	}

	for (int i = 1; (1 << i) < n; ++i) {
		for (int j = 1; (1 << j) < n; ++j) {
			vector<int> temp = standard;
			temp = mix(temp, i);
			temp = mix(temp, j);
			if (temp == result) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
}