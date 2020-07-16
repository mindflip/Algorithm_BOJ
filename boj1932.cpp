#include <iostream>
#include <vector>
#define MAX(x, y) (x > y ? x : y)

using namespace std;

int n, result;
int dp[501][501];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> dp[i][j];
        }
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j];
            } else if(j == i) {
                dp[i][j] = dp[i-1][j-1] + dp[i][j];
            } else {
                dp[i][j] = MAX(dp[i-1][j-1] + dp[i][j], dp[i-1][j] + dp[i][j]);
            }
            
            result = MAX(result, dp[i][j]);
        }
    }
    
    cout << result;
}
