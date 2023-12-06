#include<iostream>
using namespace std;

int sum(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i<size; i+=1) {
        sum += *(arr + i);  // arr[i] or i[arr]
    }
    return sum;
}

int main() {
    int arr[5] = {3, 5, 6, 8, 10};
    cout<<"Given array : "<<endl;
    for(int i : arr) {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Sum of array : "<<sum(arr, 5);
}