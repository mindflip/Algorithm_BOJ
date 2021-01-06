#include <iostream>
#include <vector>

using namespace std;

// 1. 사다리를 그래프로 구현
// 2. 각 위치의 가로선 긋는 백트래킹 구현
//    백트래킹이 끝나는 조건 : 가로선 개수(반복문 최대 m까지 계속 돌려보기)
// 3. m개에서 세로선 (시작/도착)이 (i/i)가 나오면 break 후 출력

int n, m, h;
bool ladder[11][31];
int minLadder = -1;
bool isValid;

bool checkValid() {
    // 사다리 타는 로직
    // 현재 위치 (y, x)에서 체크해야될 양쪽 가로선 (y-1, x), (y, x)
    // 1. y-1 은 왼쪽으로 옮겨감 -> (y-1, x)
    // 2. y 는 오른쪽으로 옮겨감 -> (y+1, x)
    for(int i = 1; i <= n; ++i) {
        int k = i;
        for(int j = 1; j <= h; ++j) {
            if(ladder[k][j]) k++;
            else if(ladder[k-1][j]) k--;
        }
        if(i != k) return false;
    }
    return true;
}

void findAllLadder(int num, int hCnt, int lCnt) {
    if(lCnt == num) {
        if(checkValid()) {
            isValid = true;
            minLadder = num;
        }
        return;
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = hCnt; j <= h; ++j) {
            //연속하는 가로선 없어야함
            if(!ladder[i][j] && !ladder[i-1][j] && !ladder[i+1][j]) {
                ladder[i][j] = true;
                findAllLadder(num, j, lCnt+1);
                ladder[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m >> h;
    
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        ladder[y][x] = true;
    }
    
    for(int i = 0; i <= 3; ++i) {
        findAllLadder(i, 1, 0);
        if(isValid) break;
    }
    
    cout << minLadder;
}
