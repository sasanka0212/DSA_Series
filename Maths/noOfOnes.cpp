#include<iostream>
using namespace std;

int noOfOnes(unsigned int n) {
    int count = 0;
    while(n) {
        if(n & 1)
            count++;
        n = n>>1;
    }
    return count;
}

int main() {
    unsigned int n;
    cout << "Entre n :";
    cin >> n;
    cout << "No of 1's :" << noOfOnes(n);
}