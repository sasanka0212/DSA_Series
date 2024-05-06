#include<iostream>
using namespace std; 

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateArray(int *arr, int size) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[10] = {19, 6, -3, 0, 16, 22, 31, -20, 1, 13};

    print(arr, 10);

    rotateArray(arr, 10);

    print(arr, 10);
}