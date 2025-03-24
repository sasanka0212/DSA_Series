#include<bits/stdc++.h>
#define MAXI 1000000007
using namespace std;

//approach 1 - brute force(recursion)
long long int solve(int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return 0;
    int ans = (n-1) * (solve(n-2) + solve(n-1));
    return ans;
}

//approach 2 - recursion + memorization
long long int solve1(int n, vector<long long int> &dp) {
    if(n == 2)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = ((n-1) * (solve1(n-2, dp) + solve1(n-1, dp))) % MAXI;
    return dp[n];
}

//approach 3 - tabulation
long long int solve2(int n) {
    vector<long long int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 2; i<=n; i++) {
        dp[i] = ((i-1) * (dp[i-2] + dp[i-1])) % MAXI;
    }
    return dp[n];
}

//approach 4 - space optimization
long long int solve3(int n) {
    long long int p2 = 1;
    long long int p1 = 0;
    for(int i = 2; i<=n; i++) {
        long long int temp = ((i-1) * (p2 + p1)) % MAXI;
        p2 = p1;
        p1 = temp;
    }
    return p1;
}

long long int countDerangements(int n) {
    //return solve(n);
    vector<long long int> dp(n+1, -1); //initialize with anything
    dp[1] = 0;
    return solve1(n, dp);
    //return solve2(n);
    //return solve3(n);
}

int main() {
    int n;
    cin >> n;
    cout << countDerangements(n);
    return 0;
}