#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int card;
vector<int> v;
bool check[101];
int nom;

void findAllSum(int depth, int sum) {
    if(depth == 3) {
        if(sum > nom && sum <= m) {
            nom = sum;
        }
        return;
    }
    
    for(int i = 0; i < n; ++i) {
        if(!check[i]) {
            check[i] = true;
            sum += v[i];
            findAllSum(depth + 1, sum);
            check[i] = false;
            sum -= v[i];
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        cin >> card;
        v.push_back(card);
    }
    
    findAllSum(0, 0);
    
    cout << nom;
}
