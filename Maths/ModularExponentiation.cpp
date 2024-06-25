#include<iostream>
using namespace std;

int moduleExponentiation(int a, int b, int m) {
    long long res = 1;
    long long x = a;
    while(b > 0) {
        if(b & 1) //for odd case
        {
            res = (1LL * res * (x % m)) % m;
        }
        x = (1LL * (x % m) * (x % m)) % m;
        b = b>>1;
    }
    return res;
}

int main() {
    //modular exponentiation
    int a, b, m;
    cout<<"Enter value, power & mod value : ";
    cin>>a>>b>>m;
    cout<<"Value is : "<<moduleExponentiation(a, b, m);
}