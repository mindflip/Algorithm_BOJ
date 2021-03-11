#include <iostream>

using namespace std;

// 세로, 가로
int n, m;

int main() {
    cin >> n >> m;
    
    if(n == 1) cout << 1;
    else if(n == 2) cout << min(4, (m + 1) / 2);
    else if(m < 7) cout << min(4, m);
    else if(m >= 7) cout << m - 2;
    
}
