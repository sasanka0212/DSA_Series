// how many prime numbers in the given range
#include<iostream>
#include<vector>
using namespace std;

// Time complexity -> o(n * log(logn))
// space complexity -> o(n)
int primeCount(int num) {
    int count = 0;
    vector<int> prime(num + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i<num; i++) {
        if(prime[i]) {
            count++;
            for(int n = i*2; n<=num; n = n + i) {
                prime[n] = false;
            }
        }
    }
    return count;
}

int main() {
    int num;
    cout<<"Enter a number range : ";
    cin>>num;
    cout<<"No of prime numbers : "<<primeCount(num);
}