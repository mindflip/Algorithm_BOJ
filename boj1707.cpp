#include <iostream>
#include <vector>

using namespace std;

vector<int> map[20001];
int K, V, E;
int visit[20001];  // -1 : 방문 안 한 곳 / (0, 1) : 이분
string result = "YES";

void dfs(int x, int check) {
    for(int i = 0; i < map[x].size(); ++i) {
        if(visit[map[x][i]] == -1) {
            visit[map[x][i]] = (check + 1) % 2;
            dfs(map[x][i], (check + 1) % 2);
        }
        
        if (visit[map[x][i]] == check) {
            result = "NO";
            return;
        }
    }
    
    return;
}


int main() {
    cin >> K;
    
    for(int i = 0; i < K; ++i) {
        
        for(int k = 0; k < 20001; ++k) {
            visit[k] = -1;
            map[k].clear();
        }
        
        cin >> V >> E;
        int a, b;
        for(int j = 0; j < E; ++j) {
            cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }
        
        for(int k = 1; k <= V; ++k) {
            if(visit[k] == -1){
                visit[k] = 0;
                dfs(k, 0);
            }
        }
        
        cout << result << endl;
        result = "YES";
        
    }
}
