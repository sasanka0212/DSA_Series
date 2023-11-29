// Each row is in ascending order left to right
// each col is in ascending order from top to bottom
// search a 2D matrix problem II
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int rowIndex = 0, colIndex = col - 1;
    while(rowIndex<row && colIndex>=0) {
        int val = matrix[rowIndex][colIndex];
        if(val == target) {
            return 1;
        }
        if(target > val){
            rowIndex++;
        }else{
            colIndex--;
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({1,4,7,11,15});
    matrix.push_back({2,5,8,12,19});
    matrix.push_back({3,6,9,16,22});
    matrix.push_back({10,13,14,17,24});
    matrix.push_back({18,21,23,26,30});

    cout<<"Given vector : "<<endl;
    for(vector<int> a : matrix){
        for(int val : a){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    if(searchMatrix(matrix, 17)) {
        cout<<"Element is found"<<endl;
    }else{
        cout<<"Element is not found"<<endl;
    }
}