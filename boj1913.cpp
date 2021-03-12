#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir = 0;

int n, m;
int arr[1000][1000];
int cnt = 1;
int iter = 1;
int ci = 0;
int rx, ry;

int main() {
    cin >> n >> m;
    int x = n/2;
    int y = x;
    arr[x][y] = 1;

    while(true) {
        for(int i = 0; i < iter; ++i) {
            x = x + dx[dir];
            y = y + dy[dir];
            arr[x][y] = ++cnt;
            if(cnt == m) {
                rx = x+1;
                ry = y+1;
            }
        }
        dir++;
        ci++;
        if(dir == 4) dir = 0;
        if(ci == 2) {
            if(iter != n-1) iter++;
            ci = 0;
        }

        if(cnt == n * n) break;
    }
    
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << rx << " " << ry;
    
}
