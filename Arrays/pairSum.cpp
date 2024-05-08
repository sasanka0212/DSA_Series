#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr) {
    for(vector<int> row : arr) 
        for(int i : row)
            cout << i << " ";
        cout << endl;
}

vector<vector<int>> findPairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;

    for(int i = 0; i<arr.size(); i++) {
        for(int j = i + 1; j<arr.size(); j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
} 

int main() {
    vector<int> arr = {1, 2, 4, 3, -1, -2, 2};

    vector<vector<int>> ans = findPairSum(arr, 0);
    print(ans);
}