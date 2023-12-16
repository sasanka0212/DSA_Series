#include<iostream>
using namespace std;
#include<vector>

void readNumber(int n, vector<string> a) {
    if(n == 0)  //base case
        return;
    int digit = n%10;
    n = n/10;
    readNumber(n, a);
    cout<<a[digit]<<" ";
}

int main() {
    int n;
    vector<string> a = {"Zero", "One", "Two", "Three", "Four", "Five",
                        "Six", "Seven", "Eight", "Nine"};
    cout<<"Enter number : ";
    cin>>n;

    readNumber(n, a);
}