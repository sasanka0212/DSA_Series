#include<iostream>
#include<math.h>
using namespace std;

int complementOf(int n) {
    int r = 0;
    int space = 0;
    while(n) {
        if(!(n & 1))
            r = r + (int)pow(2, space);
        space+=1;
        n = n>>1;
    }
    return r;
}

int main() {
    int n;
    cout << "Enter n :";
    cin >> n;
    cout << "Complement of " << n << " is :" << complementOf(n);
}