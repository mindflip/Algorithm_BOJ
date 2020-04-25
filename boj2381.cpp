#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

typedef pair<int, int> Point;

int N;
vector<Point> points;
vector<int> plusCoord;
vector<int> minusCoord;
int resultPlus, resultMinus;

int main(){
    cin >> N;
    
    int x, y;
    for(int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.push_back({x, y});
        plusCoord.push_back(x+y);
        minusCoord.push_back(x-y);
    }
    
    sort(plusCoord.begin(), plusCoord.end());
    sort(minusCoord.begin(), minusCoord.end());
    
    resultPlus = plusCoord[N-1] - plusCoord[0];
    resultMinus = minusCoord[N-1] - minusCoord[0];
    
    cout << MAX(resultPlus, resultMinus);
}
