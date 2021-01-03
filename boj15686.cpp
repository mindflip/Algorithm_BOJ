#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> res;
bool visit[13];
int cd = 99999999;
// m개의 치킨집 뽑기
// 치킨 거리 구하기(각 치킨집에서 집까지 최소거리 합)

int getDistance(vector<pair<int, int>> v) {
    int sum = 0;
    for(int i = 0; i < house.size(); ++i) {
        int minDis = 101;
        for(int j = 0; j < v.size(); ++j) {
            int dis = abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second);
            minDis = dis < minDis ? dis : minDis;
        }
        
        sum += minDis;
    }
    
    return sum;
}

void findAllChicken(int depth, int cnt) {
    if(depth == m) {
        int x = getDistance(res);
        cd = x < cd ? x : cd;
        
        /*
        cout << endl;
        // print positions
        for(auto e : res) {
            cout << e.first << " " << e.second << endl;
        }
        */
        
        return;
    }
    
    for(int i = cnt; i < chicken.size(); ++i) {
        if(!visit[i]) {
            visit[i] = true;
            res.push_back({chicken[i].first, chicken[i].second});
            findAllChicken(depth + 1, i + 1);
            res.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    /*
    clock_t start, end;
    
    start = clock();
    */
    cin >> n >> m;
    
    int x;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x;
            if(x == 1) house.push_back({i, j});
            if(x == 2) chicken.push_back({i, j});
        }
    }
    
    findAllChicken(0, 0);
    
    cout << cd;
    
    /*
    end = clock();
    double result = (double)(end - start);
    cout << "\n" << result;
     */
}
