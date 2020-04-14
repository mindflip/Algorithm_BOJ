#include <iostream>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;

int N;
bool visited[101][101];
char map[101][101];
int result = 0;

int dX[] = {-1, 1, 0, 0};
int dY[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    // if(visited[x][y]) return;
    visited[x][y] = true;
    
    // if(preColor == 'S') result++;
    char color = map[x][y];
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dX[i];
        int ny = y + dY[i];
        
        if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]){
            if(map[nx][ny] == color){
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[j][i];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[j][i]){
                result++;
                dfs(j, i);
            }
        }
    }
    
    cout << result << " ";
    
    result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[j][i] = false;
            if(map[j][i] == 'R') map[j][i] = 'G';
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[j][i]){
                result++;
                dfs(j, i);
            }
        }
    }
    
    cout << result;
}
