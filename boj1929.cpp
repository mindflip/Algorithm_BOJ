#include <iostream>

using namespace std;

int m, n;
int a[1000001] = {1, 1};

/*
bool isPrime(int x) {
    
    for(int i = 2; i < x; ++i) {
        if(x % i == 0) return false;
    }
    
    return true;
}
*/

int main() {
    cin >> m >> n;
    
    for(int i = 2; i <= n; ++i) {
        if(a[i]) continue;
        for(int j = 2; i*j <= n; ++j) {
            a[i*j] = 1;
        }
    }
    
    for(int i = m; i <= n; ++i) {
        if(!a[i]) printf("%d\n", i);
    }
}
