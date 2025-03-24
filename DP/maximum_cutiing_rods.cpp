#include<bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z, vector<int> &dp) {
	if(n == 0)
		return 0;
	if(n-x < 0 && n-y < 0 && n-z < 0)
		return -1;
	if(dp[n] != -1)
		return dp[n];
	dp[n] = max(max(solve(n-x, x, y, z, dp), solve(n-y, x, y, z, dp)),
					solve(n-z, x, y, z, dp));
	if(dp[n]!=-1)
		dp[n]++;
	return dp[n];
} 

int solve1(int n, int x,int y, int z, vector<int> &dp) {
	dp[0] = 0;
	for(int i = 1; i<=n; i++) {
		int p1 = (i-x < 0) ? -1 : dp[i-x];
		int p2 = (i-y < 0) ? -1 : dp[i-y];
		int p3 = (i-z < 0) ? -1 : dp[i-z];
		int maxi = max(max(p1, p2), p3);
		dp[i] = (maxi == -1) ? -1 : maxi+1;
	}
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans = solve1(n, x, y, z, dp);
	return ans==-1?0:ans;
}

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << cutSegments(n, x, y, z);
    return 0;
}