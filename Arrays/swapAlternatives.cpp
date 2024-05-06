#include<iostream>
using namespace std;

void swapAlternatve(int arr[], int size) {
    for(int i = 0; i+1<size; i+=2) {
        swap(arr[i], arr[i+1]);
    }
}

void print(int *arr, int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 4, 7, 8, 10, 18};
    print(arr, 6);

    swapAlternatve(arr, 6);
    print(arr, 6);
}