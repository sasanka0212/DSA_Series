#include<iostream>
#include<limits.h>
using namespace std;

bool isValid(int n) {
    int ans = 1;
    for(int i = 0; i < 31; i++) {
        if(ans == n)
            return true;
        if(ans < INT_MAX / 2)
            ans = ans << 1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    if(isValid(n))
        cout << "Power of two" << endl;
    else 
        cout << "Not power of two" << endl;
}