// Rat in a maze problem
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> m, vector<vector<int>> visited, int x, int y, int n) {
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> m, vector<string> &ans, string path, vector<vector<int>> &visited, int x, int y, int n) {
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    //down
    if(isSafe(m, visited, x + 1, y, n)) {
        path = path + 'D';
        solve(m, ans, path, visited, x + 1, y, n);
        path.pop_back();
    }
    if(isSafe(m, visited, x, y - 1, n)) {
        path = path + 'L';
        solve(m, ans, path, visited, x, y - 1, n);
        path.pop_back();
    }
    if(isSafe(m, visited, x, y + 1, n)) {
        path = path + 'R';
        solve(m, ans, path, visited, x, y + 1, n);
        path.pop_back();
    }
    if(isSafe(m, visited, x - 1, y, n)) {
        path.push_back('U');
        solve(m, ans, path, visited, x - 1, y, n);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if(m[0][0] == 0) {
        return ans;
    }
    int srcx = 0, srcy = 0;
    vector<vector<int>> visited = m;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, ans, path, visited, srcx, srcy, n);
    return ans;
}

int main() {
    vector<vector<int>> m = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = findPath(m, 4);
    for(string str : ans) {
        cout<<str<<endl;
    }
}