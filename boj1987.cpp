#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};

int R, C;
char map[21][21];
int alphabet[26]; //A~Z
int result = 0;

void dfs(Point start, int cnt) {
    int x = start.first;
    int y = start.second;
    
    result = max(result, cnt);
    
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < R && ny >= 0 && ny < C) {

            int k=(int)map[nx][ny]-65;
            if(alphabet[k])
                continue;

            alphabet[k]++;
            dfs({nx, ny}, cnt + 1);
            alphabet[k]--;
        }
    }
}

int main() {
    cin >> R >> C;
    
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> map[i][j];
        }
    }
    
    alphabet[(int)map[0][0]-65]++; //(0,0)지점 방문 체크
    dfs({0, 0}, 1);
    
    cout << result;
}
