#include <iostream>
#define MAX(x, y) (x > y ? x : y)

using namespace std;

int n;
int dp[100001];
int ary[100001];
int result;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> ary[i];
    }
    
    dp[0] = ary[0];
    result = dp[0];
    
    for(int i = 1; i < n; ++i) {
        dp[i] = MAX(dp[i-1] + ary[i], ary[i]);
        result = MAX(dp[i], result);
    }
    
    
    cout << result;
}
