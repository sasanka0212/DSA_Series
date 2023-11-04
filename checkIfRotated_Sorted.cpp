#include<iostream>
#include<vector>
using namespace std;

bool checkIfRotated_Sorted(vector<int> arr){
    int count = 0;
    int size = arr.size();
    for(int i = 1; i<size; i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[size-1]>arr[0]){
        count++;
    }
    return count<=1;
}

void print(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr;
    int size;
    cout<<"Enter size of array : ";
    cin>>size;
    int ele;
    for(int i = 0; i<size; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Given Array : ";
    print(arr);
    bool ans = checkIfRotated_Sorted(arr);
    cout<<ans;
}