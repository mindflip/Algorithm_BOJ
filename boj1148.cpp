#include <iostream>
#include <string>

using namespace std;

int dictionary[20001][26];

int main() {
	string str;
	int idx = 0;
	while (true) {
		cin >> str;
		if (str == "-") break;
		for (int i = 0; i < str.length(); ++i) {
			dictionary[idx][str[i]-'A']++;
		}
		idx++;
	}

	while (true) {
		cin >> str;
		if (str == "#") break;

		string miniWords = "";
		string maxiWords = "";
		int mini = 200001;
		int maxi = -1;
		int words[26] = { 0, };
		int ret[26] = { 0, };
		for (int i = 0; i < str.length(); ++i) words[str[i] - 'A']++;

		for (int i = 0; i < idx; ++i) {
			bool isValid = true;
			for (int j = 0; j < 26; ++j) {
				if (dictionary[i][j] > words[j]) {
					isValid = false;
					continue;
				}
			}
			if (!isValid) continue;
			for (int j = 0; j < 26; ++j) {
				if (dictionary[i][j] > 0) ret[j]++;
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (words[i] == 0) continue;
			if (mini > ret[i]) {
				mini = ret[i];
				miniWords = "";
				miniWords += i + 'A';
			}
			else if (mini == ret[i]) {
				miniWords += i + 'A';
			}

			if (maxi < ret[i]) {
				maxi = ret[i];
				maxiWords = "";
				maxiWords += i + 'A';
			}
			else if (maxi == ret[i]) {
				maxiWords += i + 'A';
			}
		}

		cout << miniWords << " " << mini << " ";
		cout << maxiWords << " " << maxi << "\n";
	}
}