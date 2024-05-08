#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr) {
    for(int i : arr)
        cout << i << " ";
    cout << endl;
}

void sort(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        if(arr[start] == 1) {
            swap(arr[start], arr[end]);
            end--;
        } else {
            start++;
        }
    }
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 0, 0, 1, 0 ,0, 1};

    sort(arr);
    print(arr);
}