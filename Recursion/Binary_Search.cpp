#include<iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int v) {
    if(s>e)     //base condition
        return false;
    int mid = s + (e - s) / 2;
    if(arr[mid] == v)
        return true;
    else if(arr[mid] < v)
        return binarySearch(arr, mid + 1, e, v);
    return binarySearch(arr, s, mid - 1, v);
}

int main() {
    int arr[] = {8, 11, 23, 29, 47};
    int key = 11;
    if(binarySearch(arr, 0, 4, key)) 
        cout<<"Element is found"<<endl;
    else
        cout<<"Element is not found"<<endl;
    return 0;
}