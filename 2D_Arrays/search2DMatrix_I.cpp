// binary search in a 2D matrix
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int start = 0, end = row*col-1;
    while(start<=end) {
        int mid = start + (end - start) / 2;
        int val = matrix[mid / col][mid % col];
        if(val == target){
            return 1;
        }
        if(target > val){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({1,3,5,7});
    matrix.push_back({10,11,16,20});
    matrix.push_back({23,30,34,60});

    cout<<"Given vector : "<<endl;
    for(vector<int> a : matrix){
        for(int val : a){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    if(searchMatrix(matrix, 30)) {
        cout<<"Element is found...";
    }else{
        cout<<"Element is not found...";
    }
}