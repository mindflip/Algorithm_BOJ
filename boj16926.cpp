#include <iostream>
#include <algorithm>

using namespace std;

/*
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int board[300][300];
int n, m, r, g;
int ret;

void rotate(){
    for(int i = 0; i < g; ++i) {
        int x = i;
        int y = i;
        
        int init = board[i][i];
        
        int dir = 0;
        
        while(dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >= i && nx < n-i && ny >= i && ny < m-i) {
                board[x][y] = board[nx][ny];
                x = nx;
                y = ny;
            } else {
                dir++;
            }
        }
        board[i+1][i] = init;
    }
}


int main() {
    cin >> n >> m >> r;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    
    g = min(n, m) / 2;
    
    for(int i = 0; i < r; ++i) {
        rotate();
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    
    
}
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };

int board[300][300];
int n, m, r, g;

void rotate() {
    for(int i = 0; i < g; ++i) {
        int x = i;
        int y = i;
        
        int init = board[x][y];
        
        int dir = 0;
        while(dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >= i && nx < n-i && ny >= i && ny < m-i) {
                board[x][y] = board[nx][ny];
                x = nx;
                y = ny;
            } else {
                dir++;
            }
        }
        board[i+1][i] = init;
    }
}

int main() {
    cin >> n >> m >> r;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    
    g = min(n, m) / 2;
    while(r--) {
        rotate();
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
