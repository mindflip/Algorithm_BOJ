#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c;
char g[501][501];
vector<pair<int,int>> w;
int answer = 1;

void checkResult() {
    int sz = (int)w.size();
    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < 4; ++j) {
            int x = w[i].first + dx[j];
            int y = w[i].second + dy[j];
            if(x >= 0 && x < r && y >= 0 && y < c) {
                if(g[x][y] == 'S') {
                    answer = 0;
                } else if(g[x][y] == '.') {
                    g[x][y] = 'D';
                }
            }
        }
    }
}

int main() {
    cin >> r >> c;
    
    char x;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> x;
            if(x == 'W') w.push_back({i, j});
            g[i][j] = x;
        }
    }
    
    checkResult();
    
    cout << answer << "\n";
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}
