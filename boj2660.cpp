#include <iostream>
#define INF 1000000000

using namespace std;

int N;
int a[51][51], score[51];

int main() {
    for(int i = 1; i <= 50; ++i) {
        for(int j = 1; j <= 50; ++j){
            a[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    cin >> N;
    int x, y;
    while(true) {
        cin >> x >> y;
        if(x == -1) break;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    
    int nominateScore = 51;
    for(int i = 1; i <= N; ++i) {
        int max = 0;
        for(int j = 1; j <= N; ++j) {
            max = (max < a[i][j]) ? a[i][j] : max;
        }
        score[i] = max;
        
        nominateScore = (nominateScore > max) ? max : nominateScore;
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; ++i) {
        if(score[i] == nominateScore) cnt++;
    }
    
    cout << nominateScore << " " << cnt << endl;
    
    for(int i = 1; i <= N; ++i) {
        if(score[i] == nominateScore) {
            cout << i << " ";
        }
    }
}
