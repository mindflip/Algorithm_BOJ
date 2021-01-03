#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> v, temp;
vector<string> res;
bool visit[16];
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

void findAllPassword(int cnt, int vCnt, int cCnt) {
    if(temp.size() == l) {
        string s = "";
        for(char c : temp) {
            s += c;
        }
        // cout << s << endl;
        if(vCnt >= 1 && cCnt >= 2) res.push_back(s);
        return;
    }
    
    for(int i = cnt; i < v.size(); ++i) {
        if(!visit[i]) {
            visit[i] = true;
            temp.push_back(v[i]);
            if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') findAllPassword(i + 1, vCnt + 1, cCnt);
            else findAllPassword(i + 1, vCnt, cCnt + 1);
            temp.pop_back();
            visit[i] = false;
        }
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
