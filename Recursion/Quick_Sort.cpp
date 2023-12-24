#include<iostream>
using namespace std;

int divideArray(int *arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i]<=pivot)
            cnt++;
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] >= pivot)
            j--;
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    int pivotIndex = divideArray(arr, s, e);
    quickSort(arr, s, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, e);
}

int main() {
    int arr[] = {10, 4, 20, 5, 7, 1, 15};
    quickSort(arr, 0, 6);
    for(int i : arr) {
        cout<<i<<" ";
    }
}