#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort(int arr[], int size){
    for(int i = 0; i<size - 1; i++){
        int minIndex = i;
        for(int j = i+1; j<size; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    int arr[10] = {11, 45, 4, -2, 0, 20, 5, 52, 3, 8};
    cout<<"Given Array : "<<endl;
    display(arr, 10);
    sort(arr, 10);
    cout<<"Sorted Array : "<<endl;
    display(arr, 10);
    return 0;
}