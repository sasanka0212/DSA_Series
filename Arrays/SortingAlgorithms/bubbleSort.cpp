#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j = 0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {13, 6, 19, -4, 20, 5};
    bubbleSort(arr, 6);
    for(int i : arr) {
        cout << i << " ";
    }
}