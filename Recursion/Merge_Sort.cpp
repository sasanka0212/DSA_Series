#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int* a = new int[e - s + 1];
    int mid = s + (e - s)/2;
    int i = s, j = mid + 1, k = 0;
    while(i <= mid && j<=e) {
        if(arr[i] < arr[j]) 
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++]; 
    }
    while(i<=mid) 
        a[k++] = arr[i++];
    while(j<=e){
        a[k++] = arr[j++];
    }
    k = 0;
    for(int i = s; i<=e; i++) {
        arr[i] = a[k++];
    }
    delete []a;
}

void mergeSort(int *arr, int s, int e) {
    //base case
    if(s == e) 
        return;
    int mid = s + (e - s)/2;

    //left part sort
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {
    int arr[] = {11, 6, 23, 3, 45};

    mergeSort(arr, 0, 5);
    for(int i : arr) {
        cout<<i<<" ";
    }
}