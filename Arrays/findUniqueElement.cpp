#include<iostream>
#include<vector>
using namespace std;

int findUnique(vector<int> &arr) {
    int ans = 0;
    for(int i = 0; i<arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 3, 5, 2, 1, 7, 1, 5, 2};

    cout << "Unique element is :" <<findUnique(arr);
}