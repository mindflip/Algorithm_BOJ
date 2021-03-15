#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b;
vector<int> v[10001];
bool visit[10001];
vector<int> res;
int vMax = 0;
int pMax = 0;

void bfs(int start, int cnt) {
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < (int)v[front].size(); ++i) {
            int node = v[front][i];
            if(!visit[node]) {
                visit[node] = true;
                q.push(node);
                cnt++;
            }
        }
        vMax = max(vMax, cnt);
    }
}

int main() {
    cin >> n >> m;
    
    while(m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; ++i) {
        fill(visit, visit+n+1, false);
        bfs(i, 0);
        if(pMax < vMax) {
            pMax = vMax;
            res.clear();
            res.push_back(i);
        } else if(pMax == vMax) {
            res.push_back(i);
        }
        vMax = 0;
    }
    
    sort(res.begin(), res.end());
    
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}
