#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
int g[21][21];
bool vi[21];
int minVal = 99999999;
int t1, t2;

void getSum() {
    
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(vi[i] && vi[j]) {
                t1 += g[i][j];
                t1 += g[j][i];
            }
            
            if(!vi[i] && !vi[j]) {
                t2 += g[i][j];
                t2 += g[j][i];
            }
        }
    }
    minVal = min(minVal, abs(t1-t2));
    
    t1 = 0;
    t2 = 0;
}

void dfs(int num, int cnt) {
    if(num == n/2) {
        getSum();
        return;
    }
    
    for(int i = cnt; i <= n; ++i) {
        if(!vi[i]) {
            vi[i] = true;
            dfs(num+1, i+1);
            vi[i] = false;
        }
    }
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }
    
    dfs(0, 1);
    
    cout << minVal;
}
