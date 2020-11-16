#include <iostream>

using namespace std;

int N;
int f, t;
int cnt;

int main() {
    cin >> N;
    
    f = N / 5;
    int temp = N % 5;
    while(f >= 0) {
        if(temp % 3 == 0) {
            t = temp / 3;
            temp %= 3;
            break;
        }
        f--;
        temp += 5;
    }
    
    cout << ((f + t > 0) ? f + t : -1);
}
