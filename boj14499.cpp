#include <iostream>
#include <vector>
#include <algorithm>
#define right 0
#define left 1
#define up 2
#define down 3

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m, x, y, k;
int arr[21][21];
int q[1001];

// 주사위 6면 숫자 체크, top 체크 (1-6) (2-5) (3-4)
int dice[7];

void move() {
    for(int i = 0; i < k; ++i) {
        int dir = q[i] - 1;
        x += dx[dir];
        y += dy[dir];
        
        if(x < 0 || x >= n || y < 0 || y >= m) {
            x -= dx[dir];
            y -= dy[dir];
            continue;
        } else {
            int temp[7];
            copy(dice, dice + 7, temp);
            
            switch (dir) {
                case right:
                    dice[1] = temp[4];
                    dice[4] = temp[6];
                    dice[6] = temp[3];
                    dice[3] = temp[1];
                    break;
                    
                case left:
                    dice[1] = temp[3];
                    dice[3] = temp[6];
                    dice[6] = temp[4];
                    dice[4] = temp[1];
                    break;
                    
                case up:
                    dice[1] = temp[5];
                    dice[5] = temp[6];
                    dice[6] = temp[2];
                    dice[2] = temp[1];
                    break;
                    
                case down:
                    dice[1] = temp[2];
                    dice[2] = temp[6];
                    dice[6] = temp[5];
                    dice[5] = temp[1];
                    break;
            }
        }
        
        if(arr[x][y]) {
            dice[6] = arr[x][y];
            arr[x][y] = 0;
        } else {
            arr[x][y] = dice[6];
        }
        
        cout << dice[1] << "\n";
    }
}

int main() {
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < k; ++i) {
        cin >> q[i];
    }
    
    move();
    // move a dice
    
}
