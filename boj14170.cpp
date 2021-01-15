#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int n, q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    int a, b;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        
        auto lt = lower_bound(arr, arr + n, a) - arr;
        auto rt = lower_bound(arr, arr + n, b+1) - arr;
        
        cout << (rt - lt) << "\n";
    }
}
