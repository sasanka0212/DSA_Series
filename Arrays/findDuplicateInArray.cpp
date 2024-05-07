#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> arr) {
    int ans = 0;
    for(int i = 0; i<arr.size(); i++) 
        ans = ans ^ arr[i];
    
    for(int i = 1; i<arr.size(); i++)
        ans = ans ^ i;

    return ans;
}

void print(vector<int> arr) {
    for(int i = 0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {2, 4, 5, 1, 3, 5, 6};
    print(arr);

    cout << "Duplicate element is :" << findDuplicate(arr);
}