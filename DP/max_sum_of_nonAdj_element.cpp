#include <bits/stdc++.h> 
using namespace std;

//greedy approach (recursion)
int solve2(vector<int> &nums, int i, int n) {
    if(i >= n)
        return 0;
    int maxVal = nums[i] + max(solve2(nums, i+2, n), solve2(nums, i+3, n));
    return maxVal;
}

//top-down approach (recursion + memorization)
int solve(vector<int> &nums, int i, int n, vector<int> &dp) {
    if(i >= n)
        return 0;
    if(dp[i] != INT_MIN)
        return dp[i];
    dp[i] = nums[i] + max(solve(nums, i+2, n, dp), solve(nums, i+3, n, dp));
    return dp[i];
}
//bottom-up approach (tabulation)
int solve1(vector<int> &nums, int n, vector<int> &dp) {
    for(int i = 2; i<n; i++) {
        if(i-2 >= 0 && i-3 >= 0)
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        else {
            dp[i] = nums[i] + (i-2 >= 0 ? dp[i-2] : dp[i-3]);
        }
    }
    return max(dp[n-1], dp[n-2]);
}

//Optimal approach (space optimized)
int solve3(vector<int> &nums, int n) {
    int prev1 = nums[0];
    int prev2 = 0;
    int cur = nums[1];
    for(int i = 2; i<n; i++) {
        int temp = nums[i] + max(prev1, prev2);
        prev2 = prev1;
        prev1 = cur;
        cur = temp;
    }
    return max(cur, prev1);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if(n == 1)
        return nums[0];
    vector<int> dp(n, INT_MIN);
    //dp[0] = solve(nums, 0, n, dp);
    //dp[1] = solve(nums, 1, n, dp);
    //tabulation method (bottom-up)
    //dp[0] = nums[0];
    //dp[1] = nums[1];
    //return solve1(nums, n, dp);
    //return max(solve2(nums, 0, n), solve2(nums, 1, n));
    return solve3(nums, n);   
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++)
        cin >> nums[i];
    cout << maximumNonAdjacentSum(nums);
    return 0;
}