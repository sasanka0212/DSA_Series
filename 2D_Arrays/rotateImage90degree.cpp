#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &v) {
        int i = 0, j = v.size() - 1;
        while(i < j) 
            swap(v[i++], v[j--]);
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose the matrix
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse every row of tranpose matrix
        for(int i = 0; i<n; i++) {
            reverse(matrix[i]);
        }
    }
    void print(vector<vector<int>> &matrix) {
        for(vector<int> row : matrix) {
            for(int col : row) 
                cout << col << " ";
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);

    s.print(matrix);
}