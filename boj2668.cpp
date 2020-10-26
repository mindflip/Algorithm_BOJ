#include <iostream>
#include <vector>

using namespace std;

int N;
bool visit[101];
vector<int> map;
vector<int> result;

void dfs(int start, int current) {
    if(visit[current]) {
        if(current == start) {
            result.push_back(start);
            return;
        }
    } else {
        visit[current] = true;
        dfs(start, map[current]);
    }
}

int main() {
    cin >> N;
    
    map.push_back(0);
    
    for(int i = 1; i <= N; ++i) {
        int num = 0;
        cin >> num;
        map.push_back(num);
    }
    
    for(int i = 1; i <= N; ++i) {
        dfs(i, i);
        for(int j = 0; j < 101; ++j) {
            visit[j] = false;
        }
    }
    
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}
