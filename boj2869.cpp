#include <iostream>

using namespace std;

int a, b, v;
int h;
int day;

int main() {
    cin >> a >> b >> v;
    
    if(v == a) day = 1;
    else if ((v - a) % (a - b) == 0) {
        day = (v - a) / (a - b) + 1;
    } else {
        day = (v - a) / (a - b) + 2;
    }
    
    cout << day;
}
