#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct cow {
    int x, y, p;
};

int n;
int x, y, p;
vector<cow> v;
int cows = 0;
vector<int> g[201];
bool visit[201];

void bfs(int start) {
    visit[start] = true;
    queue<int> q;
    q.push({start});
    
    int tot = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ++tot;
        
        for(int i = 0; i < g[front].size(); ++i) {
            if(!visit[g[front][i]]) {
                visit[g[front][i]] = true;
                q.push(g[front][i]);
            }
        }
    }
    cows = max(cows, tot);
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> x >> y >> p;
        v.push_back({x, y, p});
    }
    
    // tx 조건으로 그래프 연결
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            int dist = (v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y);
            // cout << dist << endl;
            if(v[i].p*v[i].p >= dist) g[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            visit[j] = false;
        }
        bfs(i);
    }
    
    cout << cows;
}

// 깊이에 대한 이해가 아직 많이 부족함
// 문제가 깊이 구하는 게 아님... 범위에 들어가서 최종까지 도달 할 수 있는 모든 커넥션 수
// 즉, 특정 노드에서 가능한 최대의 깊이가 아니라, 도달할 수 있는 모든 노드를 포함하여 최대로 연결되는 노드의 수임
