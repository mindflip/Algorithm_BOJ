#include <iostream>
#include <queue>
#define SIZE 101

using namespace std;
typedef pair<int, int> Point;

struct Ball {
    int distance;
    Point position;
};

int N, M;
bool visit[SIZE][SIZE];
int map[SIZE][SIZE];

int dX[] = {-1, 1, 0, 0};
int dY[] = {0, 0, -1, 1};

void bfs(Ball start, Point dest) {
    queue<Ball> q;
    q.push(start);
    
    while(!q.empty()) {
        Ball ball = q.front();
        q.pop();
        
        if(ball.position == dest) {
            printf("%d", ball.distance);
        }
        
        for(int i = 0; i < 4; i++) {
            Point cBall = ball.position;
            cBall.first += dX[i];
            cBall.second += dY[i];
            
            if(cBall.first >= 0 && cBall.first < N && cBall.second >= 0 && cBall.second < M && map[cBall.first][cBall.second] == 1) {
                if(!visit[cBall.first][cBall.second]) {
                    q.push({ball.distance + 1, cBall});
                    visit[cBall.first][cBall.second] = true;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    Ball start = {1, {0,0}};
    Point dest = {N-1, M-1};
    
    bfs(start, dest);
}
