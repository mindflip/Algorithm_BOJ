#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct qt {
    int x;
    int y;
    int distance;
    bool isBreak;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;
int g[1001][1001];
bool visit[1001][1001][2];

void printMap() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}

int bfs() {
    int distance = -1;
    queue<qt> q;
    q.push({0, 0, 1, false});
    visit[0][0][0] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().distance;
        int isBreak = q.front().isBreak;
        q.pop();
        
        if(x == n-1 && y == m-1) {
            distance = dist;
            break;
        }
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            bool nIsBreak = isBreak;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(g[nx][ny] == 1 && !nIsBreak) {
                    q.push({nx, ny, dist+1, !nIsBreak});
                    visit[nx][ny][!nIsBreak] = true;
                } else if(!g[nx][ny] && !visit[nx][ny][nIsBreak]) {
                    q.push({nx, ny, dist+1, nIsBreak});
                    visit[nx][ny][nIsBreak] = true;
                }
            }
            
        }
    }

    return distance;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for(int j = 0; j < m; ++j) {
            g[i][j] = input[j]-'0';
        }
    }
    
    cout << bfs();
}
