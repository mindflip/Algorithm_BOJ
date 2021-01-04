#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> seq, v;
bool visit[9];

void dfs() {
    if(v.size() == m) {
        for(int e : v) {
            cout << e << " ";
        }
        cout << "\n";
        return;
    }
    
    int before = -1;
    for(int i = 0; i < seq.size(); ++i) {
        if(!visit[i] && before != seq[i]) {
            before = seq[i];
            visit[i] = true;
            v.push_back(seq[i]);
            dfs();
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    int x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        seq.push_back(x);
    }
    
    sort(seq.begin(), seq.end());
    
    dfs();
    
}
