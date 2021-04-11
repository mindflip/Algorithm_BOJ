#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

// map을 첫 번째 칸부터 n,n 칸까지 돌면서
// 사방의 칸이 l <= <= r 조건 부합하면 layer에 통일된 번호 마스킹
// 마스킹된 번호는 1부터 시작해서 k까지 v에 넣기
// 인구수 평균 구하고 res+1, 다음날 부터 다시 반복 (v가 비어있을 때까지)
// 답 res 출력

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, l, r;
int g[51][51];
bool visit[51][51];
bool isMove = false;
vector<pair<int, int>> pos;

void printMap() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int x, int y) {
    int num = 0;
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    num++;
    sum += g[x][y];
    visit[x][y] = true;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        pos.push_back({cx, cy});
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(!visit[nx][ny] && (abs(g[cx][cy] - g[nx][ny]) >= l && abs(g[cx][cy] - g[nx][ny]) <= r)) {
                    if(!isMove) isMove = true;
                    visit[nx][ny] = true;
                    num++;
                    sum += g[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    }
    
    if(num > 1) {
        int cal = sum / num;
        for(auto p : pos) {
            g[p.first][p.second] = cal;
        }
    }
    pos.clear();
}

int main() {
    cin >> n >> l >> r;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    
    int days = 0;
    while(true) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visit[i][j]) {
                    bfs(i, j);
                }
            }
        }
        
        /*
        printMap();
        cout << "\n";
        */
        
        if(isMove) {
            days++;
            isMove = false;
        } else {
            break;
        }
        
        // init
        isMove = false;
        memset(visit, false, sizeof(visit));
        pos.clear();
    }
    
    cout << days;
    
}
