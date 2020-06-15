#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<Point, int>> ripe;
int map[1001][1001];
int M, N;
int day;
int ripeCheckCnt;
int unRipeCnt = 0;

int isAllRipe() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(map[i][j] == 0)
                return -1;
        }
    }
    
    return day;
}

void bfs() {
    while(!ripe.empty()) {
        int x = ripe.front().first.first;
        int y = ripe.front().first.second;
        int cDay = ripe.front().second;
        ripe.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(map[nx][ny] == 0) {
                    map[nx][ny] = 1;
                    ripe.push({{nx, ny}, cDay+1});
                    
                }
            }
        }
        
        day = cDay;
    }
    
    cout << isAllRipe();
}

int main() {
    cin >> M >> N;
    
    int x;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> x;
            map[i][j] = x;
            if(x == 1) ripe.push({{i, j}, 0});
            if(x == 0) unRipeCnt++;
        }
    }
    
    if(unRipeCnt == 0) {
        cout << 0;
        return 0;
    }
    
    bfs();
}
