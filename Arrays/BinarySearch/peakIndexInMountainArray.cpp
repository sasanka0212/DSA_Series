#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int peakIndex(vector<int> arr) {
        int s = 0, e = arr.size() - 1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if(arr[mid] < arr[mid+1]) {
                s = mid + 1;
            } else if(arr[mid] > arr[mid+1]) {
                e = mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {2, 5, 7, 10, 7, 1, 0};

    Solution s;
    cout << "Peak index is :" << s.peakIndex(arr); 
}