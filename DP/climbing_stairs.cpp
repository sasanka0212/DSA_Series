#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//exists overlapping subproblems
long long solve(int n, map<int, int> &m) {
    if(n == 1)
        return 1;
    if(n < 1)   
        return 0;
    m[n] = (solve(n-1, m) + solve(n-2, m)) % MOD;
    return m[n];
}

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    long long ans = solve(n, m);
    cout << ans;
    return 0;
}