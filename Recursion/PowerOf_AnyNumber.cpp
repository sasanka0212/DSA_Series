#include<iostream>
using namespace std;

long long int powerOf(int a, int b) {
    if(b == 0) 
        return 1;
    if(b == 1)
        return a;
    long long int ans = powerOf(a, b>>1);
    if(b & 1) {
        return a * ans * ans;
    }else{
        return ans * ans;
    }
}

int main() {
    int a, b;
    cout<<"Enter number & power : ";    //power must be minimum 0
    cin>>a>>b;

    long long int ans = powerOf(a, b);
    cout<<a<<"^"<<b<<" : "<<ans;
}