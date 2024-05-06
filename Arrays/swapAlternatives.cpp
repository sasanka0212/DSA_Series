#include<iostream>
using namespace std;

void swapAlternatve(int arr[], int size) {
    int first = 0;
    int second = 1;
    while(second < size) {
        swap(arr[first], arr[second]);
        first+=2;
        second+=2;
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