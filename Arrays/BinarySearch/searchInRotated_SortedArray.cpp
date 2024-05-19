#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int> arr) {
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e - s) / 2;
    while(s<e) {
        if(arr[mid] >= arr[0]) 
            s = mid + 1;
        else 
            e = mid;
        mid = s + (e - s) / 2;
    }
    return e;
}

int binarySearch(vector<int> &arr, int start, int end, int key) {
    int s = start;
    int e = end;
    while(s<=e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] == key) 
            return mid;
        else if(key > arr[mid])
            s = mid + 1;
        else    
            e = mid - 1;
    }
    return -1;
}

int findElement(vector<int> &arr, int key) {
    int index = pivotIndex(arr);
    if(key >= arr[index] && key <= arr[arr.size()-1])
        return binarySearch(arr, index, arr.size()-1, key);
    else 
        return binarySearch(arr, 0, index-1, key);
}

int main() {
    vector<int> arr = {7, 8, 11, 19, 1, 3, 6};

    cout << "Index of 3 is :" << findElement(arr, 11);
}