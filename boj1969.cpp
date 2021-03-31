#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
string str;
vector<string> v;
int hd;
char dna[4] = {'A', 'C', 'G', 'T'};
string res = "";

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        cin >> str;
        v.push_back(str);
    }
    
    int sz = (int)v.size();
    for(int i = 0; i < m; ++i) {
        map<char, int> candidate;
        for(int j = 0; j < sz; ++j) {
            candidate[v[j][i]] += 1;
        }
        
        int mc = 0;
        int mind = 0;
        for(int j = 0; j < 4; ++j) {
            if(mc < candidate[dna[j]]) {
                mind = j;
                mc = candidate[dna[j]];
            }
            hd += candidate[dna[j]];
        }
        res += dna[mind];
        hd -= candidate[dna[mind]];
    }
    
    cout << res << "\n" << hd;
}
