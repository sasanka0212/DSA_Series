#include<iostream>
using namespace std;

int sumOfVector(int *arr, int size) {
    if(size == 0)
        return 0;
    if(size == 1) 
        return arr[0];
    int sum = arr[0] + sumOfVector(arr+1, size-1);
}

int main() {
    int arr[] = {5, 1, 43, 2, 19};
    cout<<"Given array : "<<endl;
    for(int v : arr) 
        cout<<v<<" ";
    cout<<endl;
    cout<<"Sum of given array : "<<sumOfVector(arr, 5);
    return 0;
}