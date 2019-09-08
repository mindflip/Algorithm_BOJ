#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    
    string str;
    cin >> str;
    int length = (int) str.length();
    
    vector<int> number(length);
    
    int sum = 0;
    bool checkZero = false;
    
    for(int i = 0; i < length; i++) {
        number[i] = str[i] - '0';
        if(number[i] == 0) checkZero = true;
        sum += number[i];
    }
    
    sort(number.begin(), number.end(), cmp);
    
    if(sum % 3 == 0 && checkZero) {
        for(int i = 0; i < length; i++) {
            printf("%d", number[i]);
        }
    } else {
        printf("-1");
    }
}
