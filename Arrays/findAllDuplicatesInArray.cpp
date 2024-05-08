#include<iostream>
#include<vector>
#include<map>
using namespace std;

void print(vector<int> arr) {
    for(int i = 0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
} 

vector<int> findAllDuplicates(vector<int> &arr) {
    //Approach 1
    // vector<int> ans;
    // map<int, bool> temp;
    // for(int v : arr) {
    //     if(temp[v])
    //         ans.push_back(v);
    //     else    
    //         temp[v] = true;
    // }
    // return ans;

    //Approach 2
    vector<int> ans;
    for(int i = 0; i<arr.size(); i++) {
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0)
            ans.push_back(index+1);
        arr[index] = arr[index] * -1;
    }
    return ans;
}

int main() {
    vector<int> arr = {4,3,2,7,8,2,3,1};

    vector<int> ans = findAllDuplicates(arr);

    print(ans);
}