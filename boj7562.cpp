#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, -2, 2, -2, 2, 1, -1};

int tc;
int m;
bool map[301][301];
queue<Point> q;
Point src, dst;
int cnt = 0;

void bfs() {
    while(!q.empty()) {
        int size = (int)q.size();
        
        while(size--) {
            Point curPos = q.front();
            q.pop();
            
            if(curPos.first == dst.first && curPos.second == dst.second) {
                return;
            }
            
            for(int i = 0; i < 8; ++i) {
                int mx = curPos.first + dx[i];
                int my = curPos.second + dy[i];
                
                if(mx >= 0 && mx < m && my >= 0 && my < m) {
                    if(!map[mx][my]) {
                        map[mx][my] = true;
                        q.push({mx, my});
                    }
                }
            }
        }
        cnt++;
    }
}

int main() {
    cin >> tc;
    
    while(tc--) {
        cin >> m;
        
        cin >> src.first >> src.second >> dst.first >> dst.second;
        
        q.push(src);
        
        bfs();
        
        cout << cnt << endl;
        
        
        // initialization
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                map[i][j] = false;
            }
        }

        q = queue<Point>();
        
        cnt = 0;
    }
}
