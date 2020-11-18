#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<pair<int,int>, int> Point;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int g[101][101][101];
queue<Point> q;
int n, m, h;
int cnt = -1;
bool isDone = false;

void bfs() {
    while(!q.empty()) {
        int curSize = (int)q.size();
        while(curSize--) {
            Point front = q.front();
            q.pop();
            
            for(int i = 0; i < 6; ++i) {
                int mx = front.first.first + dx[i];
                int my = front.first.second + dy[i];
                int mz = front.second + dz[i];
                
                if(mx >= 0 && mx < m && my >= 0 && my < n && mz >= 0 && mz < h) {
                    if(g[mx][my][mz] == 0) {
                        g[mx][my][mz] = 1;
                        q.push({{mx, my}, mz});
                    }
                }
            }
        }
        cnt++;
    }
}

int main() {
    cin >> m >> n >> h;
    
    int t;
    
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                cin >> t;
                g[k][j][i] = t;
                if(t == 0) isDone = true;
            }
        }
    }
    
    if(!isDone) {
        cout << 0;
        return 0;
    }
    
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                if(g[k][j][i] == 1) {
                    q.push({{k, j}, i});
                }
            }
        }
    }
    
    bfs();
    
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                if(g[k][j][i] == 0) {
                    cnt = -1;
                }
            }
        }
    }
    
    cout << cnt;
}
