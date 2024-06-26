#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr) {
    for(int i : arr)
        cout << i << " ";
    cout << endl;
}

vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();
    
    vector<int> ans;
    // int restart = 0;
    // for(int i = 0; i<n; i++) {
    //     int element = arr1[i];
    //     for(int j = restart; j<m; j++) {
    //         if(element == arr2[j]) {
    //             ans.push_back(element);
    //             restart = j + 1;
    //             break;
    //         } else if(element < arr2[i]) {
    //             break;
    //         }
    //     }
    // }
    // return ans;

    int i = 0, j = 0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            j++;
            i++;
        } else if(arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 2, 3, 4, 5, 10};
    vector<int> arr2 = {2, 2, 3, 3, 4, 20};

    vector<int> ans = intersection(arr1, arr2);
    print(ans);
}