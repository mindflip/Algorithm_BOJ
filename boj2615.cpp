#include <iostream>

using namespace std;

typedef pair<int, int> pos;

int dx[4] = { -1, 0, 1, 1 };
int dy[4] = { 1, 1, 1, 0 };

int board[19][19];
bool visit[19][19][4];
int ret;
pos start;

void dfs(pos cur, int depth, int dir, int color) {
    pos next = {cur.first + dx[dir], cur.second + dy[dir]};
    if(next.first < 0 || next.first >= 19 || next.second < 0 || next.second >= 19 || board[next.first][next.second] != color) {
        if(depth == 5) ret = color;
        return;
    }
    
    visit[next.first][next.second][dir] = true;
    dfs(next, depth + 1, dir, color);
}

int main() {
    for(int i = 0; i < 19; ++i) {
        for(int j = 0; j < 19; ++j) {
            cin >> board[i][j];
        }
    }
    
    for(int j = 0; j < 19; ++j) {
        if(ret != 0) break;
        for(int i = 0; i < 19; ++i) {
            if(ret != 0) break;
            if(board[i][j] == 0) continue;
            start = { i, j };
            for(int dir = 0; dir < 4; ++dir) {
                if(visit[i][j][dir]) continue;
                visit[i][j][dir] = true;
                dfs(start, 1, dir, board[i][j]);
            }
        }
    }
                
    cout << ret << "\n";
    if(ret != 0) cout << start.first + 1 << " " << start.second + 1;
}
