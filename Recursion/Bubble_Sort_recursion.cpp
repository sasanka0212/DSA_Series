#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr, int size) {
    if(size == 0 || size == 1) 
        return;
    for(int i = 0; i<size-1; i++) {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, size-1);
}

int main() {
    vector<int> arr = {10, 7, 21, 3, 19};
    bubbleSort(arr, arr.size());

    cout<<"Sorted Array : "<<endl;
    for(int v : arr)
        cout<<v<<" ";
    cout<<endl;
}