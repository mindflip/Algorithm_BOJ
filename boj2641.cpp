#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
string s = "", rs = "";
vector<string> seq;
vector<string> result;

bool checkPolygon(string sample) {
    for(int i = 0; i < s.length(); ++i) {
        if(rs == sample || s == sample) {
            return true;
        }
        sample = sample.substr(1) + sample[0];
    }
    return false;
}

int main() {
    cin >> N;
    
    char c;
    for(int i = 0; i < N; ++i) {
        cin >> c;
        s += c;
    }
    
    for(int i = 0; i < N; ++i) {
        int temp = ((int)s[N-1-i]) - 48;
        // cout << temp << endl;
        rs += ((temp + 2) == 4) ? to_string(4) : to_string((temp + 2) % 4);
    }
    
    // cout << s << endl;
    // cout << rs << endl;
    
    cin >> M;
    for(int i = 0; i < M; ++i) {
        char sc;
        seq.push_back("");
        for(int j = 0; j < N; ++j) {
            cin >> sc;
            seq[i] += sc;
        }
    }
    
    for(int i = 0; i < seq.size(); ++i) {
        if(checkPolygon(seq[i])) {
            result.push_back(seq[i]);
        }
    }
    
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < N; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
