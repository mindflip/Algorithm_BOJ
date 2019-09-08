#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
bool visit[1001];
bool visitd[1001];
vector<int> a[10001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if(!visit[y]) {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}

void dfs(int x) {
    if (visitd[x]) return;
    visitd[x] = true;
    printf("%d ", x);
    
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(!visitd[y]) {
            dfs(y);
        }
    }
}

int main() {
    cin >> N >> M >> V;
    
    int v1, v2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    for(int i = 0; i < M; i++) {
        sort(a[i].begin(), a[i].end());
    }
    
    
    dfs(V);
    printf("\n");
    bfs(V);
    
}
