#include <iostream>
#include <queue>
#define MAX(a, b) (a > b ? a : b)

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N;
int map[101][101];
bool visit[101][101];
queue<Point> q;
int cntResult = 0;

// 디버깅을 위한 맵 프린팅 함수
void printMap() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void visitUpdate() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            visit[i][j] = false;
        }
    }
}

void bfs(int height) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == false && map[nx][ny] > height) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> N;
    
    int x;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> x;
            map[i][j] = x;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i <= 100; ++i) {
        visitUpdate();
        for(int n = 0; n < N; ++n) {
            for(int m = 0; m < N; ++m) {
                if(visit[n][m] == false && map[n][m] > i) {
                    visit[n][m] = true;
                    q.push({n, m});
                    bfs(i);
                    ++cnt;
                }
            }
        }
        
        cntResult = MAX(cntResult, cnt);
        cnt = 0;
    }
    
    cout << cntResult;
}
