#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while(s < e) {
        if(arr[mid] >= arr[0])
            s = mid + 1;
        else 
            e = mid;
        mid = s + (e - s) / 2;
    }
    return s;   //at the end both start & end index are same
}

int main() {
    vector<int> arr = {8, 17, 20, 21, 4, 6};

    cout << "Pivot index is :" << pivotIndex(arr);
}