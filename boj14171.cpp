#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, cnt;
string arr[200001];
map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    string a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[i] = a.substr(0, 2) + b;
        if(m.count(arr[i])) {
            m[arr[i]] += 1;
        } else {
            m.insert({a.substr(0, 2) + b, 1});
        }
    }
    
    for(int i = 0; i < n; ++i) {
        string rStr = arr[i].substr(2, 2) + arr[i].substr(0, 2);
        if(arr[i] == rStr) continue;
        if(m.count(rStr)) {
            cnt += m[rStr];
        }
    }
    
    cout << cnt/2;
}
