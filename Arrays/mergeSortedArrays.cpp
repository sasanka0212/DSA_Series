#include<iostream>
#include<vector>
using namespace std;

vector<int> sort(vector<int> arr1, vector<int> arr2, vector<int> arr3){
    int first = 0, last = 0, k = 0;
    while(first < arr1.size() && last < arr2.size()){
        if(arr1[first] > arr2[last]){
            arr3[k++] = arr2[last++];
        }else{
            arr3[k++] = arr1[first++];
        }
    }
    while(first < arr1.size()){
        arr3[k++] = arr1[first++];
    }
    while(last < arr2.size()){
        arr3[k++] = arr2[last++];
    }
    return arr3;
}

void display(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr1;
    vector<int> arr2;

    //1st array elements
    arr1.push_back(17);
    arr1.push_back(21);
    arr1.push_back(30);
    arr1.push_back(53);
    arr1.push_back(88);

    //2nd array elements
    arr2.push_back(15);
    arr2.push_back(16);
    arr2.push_back(55);
    arr2.push_back(70);

    vector<int> arr3(9,0);

    cout<<"1st Array : "<<endl;
    display(arr1);
    cout<<"2nd Array : "<<endl;
    display(arr2);
    arr3 = sort(arr1,arr2,arr3);
    cout<<"Merged sorted Array : "<<endl;
    display(arr3);
}