#include <iostream>
#define MIN(x, y) (x < y ? x : y)

using namespace std;

int ary[1001][3];
int dp[1001][3];
int N;

int main() {
    cin >> N;
    
    int r, g, b;
    for(int i = 0; i < N; ++i) {
        cin >> r >> g >> b;
        ary[i][0] = r;
        ary[i][1] = g;
        ary[i][2] = b;
    }
    
    dp[0][0] = ary[0][0];
    dp[0][1] = ary[0][1];
    dp[0][2] = ary[0][2];
    
    for(int i = 1; i < N; ++i) {
        dp[i][0] = MIN(dp[i-1][1], dp[i-1][2]) + ary[i][0];
        dp[i][1] = MIN(dp[i-1][0], dp[i-1][2]) + ary[i][1];
        dp[i][2] = MIN(dp[i-1][0], dp[i-1][1]) + ary[i][2];
    }
    
    cout << MIN(MIN(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}
