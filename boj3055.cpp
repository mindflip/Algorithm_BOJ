#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int R, C;
char map[51][51];
Point dest;
Point src;
queue<Point> water;
queue<Point> hedgehog;
int cnt = 0;

// 디버깅을 위한 지도 출력
void printMap() {
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs() {
    
    while(!hedgehog.empty()) {
        int wSize = (int)water.size();
        while(wSize--) {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    if(map[nx][ny] == '.') {
                        map[nx][ny] = '*';
                        water.push({nx, ny});
                    }
                }
            }
        }
        
        cnt++;

        int hedgeSize = (int)hedgehog.size();
        while(hedgeSize--) {
            Point curPos = hedgehog.front();
            hedgehog.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nx = curPos.first + dx[i];
                int ny = curPos.second + dy[i];
                
                if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    if(map[nx][ny] == '.') {
                        map[nx][ny] = 'S';
                        hedgehog.push({nx, ny});
                    } else if(map[nx][ny] == 'D') {
                        cout << cnt;
                        return;
                    }
                }
            }
        }
    }
    
    cout << "KAKTUS";
}

int main() {
    cin >> R >> C;
    
    char x;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> x;
            map[i][j] = x;
            if(x == '*') water.push({i, j});
            if(x == 'D') dest = {i,j};
            if(x == 'S') hedgehog.push({i ,j});
        }
    }
    
    bfs();
}
