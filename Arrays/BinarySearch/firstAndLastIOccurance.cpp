#include<iostream>
#include<vector>
using namespace std;

pair<int, int> findFirstAndLastIndex(vector<int> &arr, int key) {
    pair<int, int> ans = make_pair(-1, -1);

    int start = 0;
    int end = arr.size() - 1;
    //first occurance
    while(start<=end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) {
            ans.first = mid;
            end = mid - 1;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end  = mid - 1;
        }
    }

    start = 0;
    end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) {
            start = mid + 1;
            ans.second = mid; 
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 1, 3, 3, 3, 7, 9, 10};

    pair<int, int> ansIndex = findFirstAndLastIndex(arr, 1);
    cout << endl << "First Index :" << ansIndex.first << endl;
    cout << endl << "Last Index :" << ansIndex.second << endl;
}