#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int M, N, K;
int map[101][101];
int visit[101][101];
int cnt = 0;
int sectorCnt = 0;
vector<int> wide;

// 디버깅을 위한 맵 프린팅
void printMap() {
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}


void dfs(Point start) {
    int x = start.first;
    int y = start.second;
    visit[x][y] = true;
    cnt += 1;
    
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visit[nx][ny] && map[nx][ny] == 0) {
            dfs({nx, ny});
        }
    }
}

int main() {
    cin >> M >> N >> K;
    
    int a, b, c, d;
    for(int i = 0; i < K; ++i) {
        cin >> a >> b >> c >> d;
        
        for(int n = a; n < c; ++n) {
            for(int m = b; m < d; ++m) {
                map[m][n] = 1;
            }
        }
    }
    
    // printMap();
    
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(map[i][j] == 0 && !visit[i][j]) {
                dfs({i, j});
                sectorCnt += 1;
                wide.push_back(cnt);
                cnt = 0;
                
            }
        }
    }
    
    cout << sectorCnt << endl;
    sort(wide.begin(), wide.end());
    for(int i = 0; i < wide.size(); ++i) {
        cout << wide[i] << " ";
    }
}
