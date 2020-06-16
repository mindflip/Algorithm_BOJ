#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int T, M, N, K;
bool visit[51][51];
int map[51][51];
int cnt;

void printMap(int n, int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    visit[x][y] = true;
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && visit[nx][ny] == false) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> T;
    
    int x, y;
    for(int t = 0; t < T; ++t) {
        cin >> M >> N >> K;
        cnt = 0;
        for(int n = 0; n < N; ++n) {
            for(int m = 0; m < M; ++m) {
                visit[n][m] = false;
                map[n][m] = 0;
            }
        }
        
        for(int k = 0; k < K; ++k) {
            cin >> y >> x;
            map[x][y] = 1;
        }
        
        // printMap(N, M);
        
        for(int n = 0; n < N; ++n) {
            for(int m = 0; m < M; ++m) {
                if(map[n][m] == 1 && visit[n][m] == false) {
                    bfs(n, m);
                    cnt = cnt + 1;
                }
            }
        }

        cout << cnt << endl;
    }
}
