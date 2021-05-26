#include <iostream>

using namespace std;

int n, m;
int arr[1000001];
long long mid, high, low;
long long ret;
int maxi = 0;

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(maxi < arr[i]) maxi = arr[i];
    }
    
    low = 1;
    high = maxi;
    
    while(low <= high) {
        mid = low + high >> 1;
        
        long long len = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] - mid > 0) len += arr[i] - mid;
        }
        
        if(len < m) {
            high = mid - 1;
        } else {
            low = mid + 1;
            ret = mid;
        }
    }
    
    cout << ret;
}
