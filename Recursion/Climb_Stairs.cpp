#include<iostream>
using namespace std;

// You have two options 
// Either you can jump one stair or two stair
int countPossibleWays(long long nStairs) {
    if(nStairs == 0)
        return 1;
    if(nStairs < 0) 
        return 0;
    int count = countPossibleWays(nStairs-1) + countPossibleWays(nStairs-2);
    return count;
}

int main() {
    long long nStairs;
    cout<<"Enter nth stair : ";
    cin>>nStairs;

    cout<<"No of possible ways to climb nth stair : " <<countPossibleWays(nStairs);
}