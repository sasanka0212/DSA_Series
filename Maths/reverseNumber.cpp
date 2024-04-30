#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int n) {
    int ans = 0;
    while(n != 0) {
        int rem = n % 10;
        n /= 10;
        //2147483648
        if(ans > INT_MAX / 10 || ans < INT_MIN / 10) {
            ans = 0;
            break;
        }
        ans = ans * 10 + rem;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << "Reverse of n " << reverse(n);
}