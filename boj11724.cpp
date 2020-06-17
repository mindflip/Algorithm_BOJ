#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int u, v;
vector<int> graph[1001];
bool visit[1001];
int cnt = 0;

void bfs(int input) {
    queue<int> q;
    q.push(input);
    
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < graph[front].size(); ++i) {
            int x = graph[front][i];
            if(visit[x] == false) {
                q.push(x);
                visit[x] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < M; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i = 1; i <= N; ++i) {
        if(!visit[i]){
            bfs(i);
            visit[i] = true;
            ++cnt;
        }
    }
    
    cout << cnt;
}
