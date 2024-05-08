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
    int index = 0;

    while(index <= end) {   //important condition
        if(arr[index] == 0) {
            swap(arr[index], arr[start]);
            index++;
            start++;
        } else if(arr[index] == 2) {
            swap(arr[index], arr[end]);
            end--;
        } else {
            index++;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 1, 0, 1, 1, 2, 0, 0, 2};

    sort(arr);
    print(arr);
}