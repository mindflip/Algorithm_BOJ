#include <iostream>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N, M;
char map[2001][2001];
int cntTile;

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            for(int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if(map[i][j] != map[nx][ny]) {
                        ++cntTile;
                        break;
                    }
                }
            }
        }
    }
    
    int r = 1;
    for(int i = 0; i < (N*M) - cntTile; i++)
    {
        r = (r * 2) % 1000000007;
    }
    int result = r;
    //double result = fmod(pow(2, (N * M) - cntTile), 1000000007);
    
    cout << result;
}
