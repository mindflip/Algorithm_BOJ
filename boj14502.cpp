#include <iostream>
#include <queue>
#include <algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

typedef pair<int, int> Point;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int N, M;
bool visited[9][9];
int map[9][9];
int tMap[9][9];
int ans = 0;

// map 상황 프린트를 위해 짠 메서드. 알고리즘과 상관x
void printMap() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(){
    copy(&map[0][0], &map[0][0] + 9 * 9, &tMap[0][0]);
    
    queue<Point> q;
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) {
            if(tMap[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(tMap[nx][ny] == 0) {
                    q.push({nx, ny});
                    tMap[nx][ny] = 2;
                }
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) {
            if(tMap[i][j] == 0)
                cnt++;
        }
    }
    
    ans = MAX(ans, cnt);
}

void makeWalls(int cnt) {
    if(cnt == 3) {
        bfs();
        return;
    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                makeWalls(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(map[i][j] == 0) {
                map[i][j] = 1;
                makeWalls(1);
                map[i][j] = 0;
            }
        }
    }
    
    cout << ans;
}
