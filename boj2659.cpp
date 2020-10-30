#include <iostream>

using namespace std;

int a[4];

int getClockNum(int x) {
    int temp = x;
    
    for(int i = 0; i < 3; ++i) {
        x = (x % 1000 * 10) + (x / 1000);
        if(temp > x) temp = x;
    }
    
    return temp;
}

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    
    int clockNum = getClockNum(a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]);
    
    int cnt = 0;
    for(int i = 1111; i <= clockNum; ++i) {
        if(getClockNum(i) == i) cnt++;
    }
    
    cout << cnt;
}




/*
#include <iostream>

using namespace std;

int input[4];

int calCrossNumber(int x) {
    int temp = x;
    for(int i = 0; i < 3; ++i) {
        x = (x % 1000 * 10) + (x / 1000);
        if(temp > x) temp = x;
        // cout << x << endl;
    }
    
    return temp;
}

int main() {
    cin >> input[0] >> input[1] >> input[2] >> input[3];
    
    int crossNumber = calCrossNumber(input[0] * 1000 + input[1] * 100 + input[2] * 10 + input[3]);
    // cout << crossNumber;
    int cnt = 0;
    
    for(int i = 1111; i <= crossNumber; ++i) {
        if(calCrossNumber(i) == i) cnt++;
    }
    
    cout << cnt;
}

*/
