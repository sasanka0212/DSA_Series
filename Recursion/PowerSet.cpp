#include<iostream>
#include<vector>
using namespace std;

void powerSet(vector<int> arr, vector<int> output, vector<vector<int>> &ans, int index) {
    if(index == arr.size()) {
        ans.push_back(output);
        return;
    }

    //exclude the element
    powerSet(arr, output, ans, index + 1);
    //include the element
    output.push_back(arr[index]);
    powerSet(arr, output, ans, index + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    powerSet(arr, output, ans, 0);
    for(vector<int> a : ans) {
        for(int v : a) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}