#include<iostream>
using namespace std;

void rowMajorSum(int matrix[][3], int row, int col){
    cout<<"Row wise sum : "<<endl;
    for(int i = 0; i<row; i++){
        int sum = 0;
        for(int j = 0; j<3; j++){
            sum += matrix[i][j];
        }
        cout<<"Sum of row no. "<<i<<"->"<<sum<<endl;
    }
}

int main(){
    int matrix[3][3];
    cout<<"Enter elements : "<<endl;
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            cin>>matrix[i][j];

    cout<<"Given matrix : "<<endl;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    rowMajorSum(matrix, 3, 3);
}