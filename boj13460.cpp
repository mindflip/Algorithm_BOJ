#include <iostream>
#include <queue>
#include <utility>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;
typedef pair<int, int> Point;

struct Ball {
    int depth;
    Point red;
    Point blue;
};

char map[11][11];
bool visited[11][11][11][11];
int N, M;

int dX[] = {0, 0, -1, 1};
int dY[] = {-1, 1, 0, 0};

inline void doMove(Point &ball, int dir){
    while(true){
        ball.first += dY[dir];
        ball.second += dX[dir];
        
        char cell = map[ball.first][ball.second];
        if (cell == 'O') {
            break;
        }
        else if (cell == '#') {
            ball.first -= dY[dir];
            ball.second -= dX[dir];
            break;
        }
    }
}

int main(){
    cin >> N >> M;
    
    Point red, blue;
    Point hole;
    
    for(int n = 1; n <= N; n++) {
        for(int m =1; m <= M; m++) {
            cin >> map[n][m];
            switch (map[n][m]) {
                case 'O':
                    hole = {n, m};
                    break;
                case 'R':
                    red = {n, m};
                    break;
                case 'B':
                    blue = {n, m};
                    break;
            }
        }
    }
    
    int depth = -1;
    queue<Ball> q;
    q.push(Ball{0, red, blue});
    
    while(!q.empty()) {
        Ball ball = q.front();
        q.pop();
        
        if(ball.depth > 10) break;
        
        if(ball.red == hole) {
            depth = ball.depth;
            break;
        }
        
        
        for(int i = 0; i < 4; i++) {
            Point cRed = ball.red, cBlue = ball.blue;
            doMove(cRed, i);
            doMove(cBlue, i);
            
            if (cBlue == hole) continue;
            
            if (cRed == cBlue) {
                if (i == UP) {
                    if (ball.red.first < ball.blue.first) {
                        cBlue.first++;
                    } else {
                        cRed.first++;
                    }
                } else if (i == DOWN) {
                    if (ball.red.first < ball.blue.first) {
                        cRed.first--;
                    } else {
                        cBlue.first--;
                    }
                } else if (i == LEFT) {
                    if (ball.red.second < ball.blue.second) {
                        cBlue.second++;
                    } else {
                        cRed.second++;
                    }
                } else if (i == RIGHT) {
                    if (ball.red.second < ball.blue.second) {
                        cRed.second--;
                    } else {
                        cBlue.second--;
                    }
                }
            }
            
            if(!visited[cRed.first][cRed.second][cBlue.first][cBlue.second]) {
                q.push(Ball{ball.depth + 1, cRed, cBlue});
                visited[cRed.first][cRed.second][cBlue.first][cBlue.second] = true;
            }
        }
    }
    
    cout << depth << endl;
}
