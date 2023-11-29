#include<iostream>
#include<vector>
using namespace std;

vector<int> waveVector(vector<vector<int>> arr){
    int nRows = arr.size(), mCols = arr[0].size();
    vector<int> ans;
    for(int col = 0; col<mCols; col++){
        if(col & 1){
            for(int row = nRows - 1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }else{
            for(int row = 0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr;
    arr.push_back({12, 5, 9});
    arr.push_back({10, 2, 21});
    arr.push_back({1, 7, 8});

    cout<<"Given vector : "<<endl;
    for(vector<int> a : arr){
        for(int val : a){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    vector<int> ans = waveVector(arr);
    cout<<"Wave vector : "<<endl;
    for(int a : ans){
            cout<<a<<" ";
    }
}