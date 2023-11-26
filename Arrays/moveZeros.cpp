#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int> &arr){
    int i = 0, j = 0;
    while(j<arr.size()){
        if(arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}

void print(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;
}

int main(){
    vector<int> arr = {0,5,1,2,0,6,0,11};
    cout<<"Given Array : ";
    print(arr);
    moveZeros(arr);
    cout<<"Array after move zeros : ";
    print(arr);
    return 0;
}