#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> rope(N);
    
    for(int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    
    sort(rope.begin(), rope.end());

    for(int i = 0; i < N; i++) {
        rope[i] = rope[i] * (N-i);

    }
    
    cout << *max_element(rope.begin(), rope.end());

}
