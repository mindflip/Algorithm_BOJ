#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c, t;
int board[50][50][2];
int upx = -1, upy, downx, downy;

void spread(int cur) {
    int next = (cur+1)%2;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(board[i][j][cur] == -1) board[i][j][next] = board[i][j][cur];
            else board[i][j][next] = 0;
        }
    }
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(board[i][j][cur] == 0 || board[i][j][cur] == -1) continue;
            int value = board[i][j][cur] / 5;
            int candi = 0;
            for(int dir = 0; dir < 4; ++dir) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny][cur] == -1) continue;
                board[nx][ny][next] += value;
                candi += value;
            }
            board[i][j][next] += board[i][j][cur] - candi;
        }
    }
}

void moveDust(int cur) {
    for(int x = upx-1; x > 0; --x) {
        board[x][0][cur] = board[x-1][0][cur];
    }
    for(int y = 0; y < c-1; ++y) {
        board[0][y][cur] = board[0][y+1][cur];
    }
    for(int x = 0; x < upx; ++x) {
        board[x][c-1][cur] = board[x+1][c-1][cur];
    }
    for(int y = c-1; y > 1; --y) {
        board[upx][y][cur] = board[upx][y-1][cur];
    }
    board[upx][1][cur] = 0;
    
    for(int x = downx+1; x < r-1; ++x) {
        board[x][0][cur] = board[x+1][0][cur];
    }
    for(int y = 0; y < c-1; ++y) {
        board[r-1][y][cur] = board[r-1][y+1][cur];
    }
    for(int x = r-1; x > downx; --x) {
        board[x][c-1][cur] = board[x-1][c-1][cur];
    }
    for(int y = c-1; y > 1; --y) {
        board[downx][y][cur] = board[downx][y-1][cur];
    }
    board[downx][1][cur] = 0;
}

int main() {
    cin >> r >> c >> t;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> board[i][j][0];
            if(board[i][j][0] == -1) {
                if(upx == -1) {
                    upx = i;
                    upy = j;
                } else {
                    downx = i;
                    downy = j;
                }
            }
        }
    }
    
    int cur = 0;
    while(t--) {
        spread(cur);
        cur = (cur+1)%2;
        moveDust(cur);
    }
    
    int ret = 0;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(board[i][j][cur] != -1) ret += board[i][j][cur];
        }
    }
    
    cout << ret;
}
