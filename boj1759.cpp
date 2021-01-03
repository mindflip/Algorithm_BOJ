#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> v, temp;
vector<string> res;

void findAllPassword(int cnt, int vCnt, int cCnt) {
    if(temp.size() == l) {
        string s = "";
        for(char c : temp) {
            s += c;
        }
        if(vCnt >= 1 && cCnt >= 2) res.push_back(s);
        return;
    }
    
    for(int i = cnt; i < v.size(); ++i) {
        temp.push_back(v[i]);
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') findAllPassword(i + 1, vCnt + 1, cCnt);
        else findAllPassword(i + 1, vCnt, cCnt + 1);
        temp.pop_back();
    }
}

int main() {
    cin >> l >> c;
    
    char x;
    for(int i = 0; i < c; ++i) {
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    findAllPassword(0, 0, 0);
    
    for(string s : res) {
        cout << s << endl;
    }
}
