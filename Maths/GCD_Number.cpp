#include<iostream>
using namespace std;

//lcm(a,b) * gcd(a,b) = a * b
int gcd(int a, int b) {
    if(a==0)
        return b;
    if(b==0) 
        return a;
    while(a!=b) {
        if(a>b) 
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main() {
    int a, b;
    cout<<"Enter 2 no : ";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" : "<<gcd(a, b);
}