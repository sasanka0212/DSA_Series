#include<bits/stdc++.h> 
using namespace std;
//recursion + memorization
int solve(vector<int> &num, int x, int n, vector<int> &dp) {
    if(x < 0)
        return INT_MAX;
    if(dp[x] != -1)
        return dp[x];
    dp[x] = INT_MAX;
    for(int i = 0; i<n; i++) {
        dp[x] = min(dp[x], solve(num, x-num[i], n, dp));
    }
    if(dp[x] != INT_MAX)
        dp[x] = dp[x] + 1;
    return dp[x];
}
//tabulation
int solve1(vector<int> &num, int x, int n, vector<int> &dp) {
    for(int k = 1; k<=x; k++) {
        dp[k] = INT_MAX;
        for(int i = 0; i<n; i++) {
            if(k-num[i] >= 0)
                dp[k] = min(dp[k], dp[k - num[i]]);
        }
        if(dp[k] != INT_MAX)
            dp[k] = dp[k] + 1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> dp(x+1, -1);
    dp[0] = 0;
    //dp[x] = solve(num, x, n, dp);
    dp[x] = solve1(num, x, n, dp);
    return dp[x] == INT_MAX ? -1 : dp[x];
}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> num(n, 0);
    for(int i = 0; i<n; i++) {
        int c;
        cin >> c;
        num[i] = c;
    }
    cout << minimumElements(num, x);
    return 0;
}