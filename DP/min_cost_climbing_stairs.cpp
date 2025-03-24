#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        //top-down approach with memorization
        int solve(int n, vector<int> &cost, vector<int> &dp) {
            if(n==0)
                return cost[0];
            if(n==1)
                return cost[1];
            if(dp[n] != -1)
                return dp[n];
            dp[n] = min(solve(n-1, cost, dp), solve(n-2, cost, dp)) + cost[n];
            return dp[n];
        }
        //bottom-up approach 
        int solve1(int n, vector<int> &cost, vector<int> &dp) {
            for(int i = 2; i<n; i++) {
                dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
                //cost[n] doesn't exist
            }
            dp[n] = min(dp[n-1], dp[n-2]);
            return dp[n];
        }
        //space optimization
        int solve2(int n, vector<int> &cost) {
            int mini1 = cost[1];
            int mini2 = cost[0];
            for(int i = 2; i<n; i++) {
                int temp = min(mini1, mini2) + cost[i];
                mini2 = mini1;
                mini1 = temp;
            }
            return min(mini1, mini2);
        }
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n+1, -1);
            dp[0] = cost[0];
            dp[1] = cost[1];
            //dp[n] = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
            //int ans = solve1(n, cost, dp);
            int ans = solve2(n, cost);
            return ans;
        }
};

int main() {
    Solution s;
    vector<int> cost = {10, 15, 20, 6, 19};
    cout << s.minCostClimbingStairs(cost);
    return 0;
}