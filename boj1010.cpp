#include <iostream>

using namespace std;

int t, n, m;
int dp[31][31];

int bc(int n, int k) {
    if(n == k || k == 0) return 1;
    if(dp[n][k]) return dp[n][k];
    return dp[n][k] = bc(n-1, k-1) + bc(n-1, k);
}

int main() {
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        cout << bc(m, n) << "\n";
    }
}
