#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector<int> arr, int k){
    int n = arr.size();
    vector<int> temp(n,0);
    for(int i = 0; i<n; i++){
        temp[(i+k)%n] = arr[i];
    }
    arr = temp;
    return arr;
}

void display(vector<int> arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(14);
    arr.push_back(31);
    arr.push_back(40);
    arr.push_back(77);

    cout<<"Given Array : ";
    display(arr);

    int k;
    cout<<"Enter rotation of array(1-5) : ";
    cin>>k;

    arr = rotate(arr,k);
    cout<<"Rotated Array : ";
    display(arr);
}