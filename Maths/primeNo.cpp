#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter no : ";
    cin >> n;

    bool isPrime = true;

    for(int i = 2; i<=n/2; i++) {
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
        cout << n << " is a prime no" << endl;
    else 
        cout << n << " is not a prime no" << endl;
}