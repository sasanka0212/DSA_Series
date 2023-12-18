//Linear search in Array
#include<iostream>
using namespace std;

bool linearSearch(int *arr, int size, int v) {
    if(size < 1) 
        return false;
    if(arr[0] == v) 
        return true;
    //recursive call
    return linearSearch(arr + 1, size - 1, v);
}

int main() {
    int arr[] = {6, 10, 2, 44, 11};
    if(linearSearch(arr, 5, 4))
        cout<<"Element is found"<<endl;
    else    
        cout<<"Element is not found"<<endl;
    return 0;
}