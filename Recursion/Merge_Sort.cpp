#include<iostream>
using namespace std;

/*
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
*/

void merge(int *arr, int s, int e) {
    int mid = s + (e-s)/2;
    int size1 = mid-s+1;
    int size2 = e-mid;
    int *first = new int[size1];
    int *second = new int[size2];
    int k = s;
    for(int i = 0; i<size1; i++) 
        first[i] = arr[k++];
    k = mid+1;
    for(int i = 0; i<size2; i++) 
        second[i] = arr[k++];
    int minIndex = s;
    int len1 = 0, len2 = 0;
    while(len1 < size1 && len2 < size2) {
        if(first[len1] < second[len2])
            arr[minIndex++] = first[len1++];
        else
            arr[minIndex++] = second[len2++];
    } 
    while(len1 < size1)
        arr[minIndex++] = first[len1++];
    while(len2 < size2) 
        arr[minIndex++] = second[len2++];
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e) {
    //base case
    if(s >= e) 
        return;
    int mid = s + (e - s)/2;

    //left part sort
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {
    int arr[] = {11, 6, 23, 3, 45};

    mergeSort(arr, 0, 4);
    for(int i : arr) {
        cout<<i<<" ";
    }
}