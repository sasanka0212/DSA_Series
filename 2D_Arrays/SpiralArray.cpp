// convert a 2d matrix into spiral array
#include<iostream>
using namespace std;

void spiralArray(int matrix[][3], int row, int col){
    int arr[12];
    int startRow = 0, endRow = row - 1;
    int startCol = 0, endCol = col - 1;
    int count = 0, total = row * col;
    while(count < total){
        for(int i = startCol; i<=endCol && count<total; i++){
            arr[count++] =  matrix[startRow][i];
        }
        startRow++;
        for(int i = startRow; i<=endRow && count<total; i++){
            arr[count++] = matrix[i][endCol];
        }
        endCol--;
        for(int i = endCol; i>=startCol && count<total; i--){
            arr[count++] = matrix[endRow][i];
        }
        endRow--;
        for(int i = endRow; i>=startRow && count<total; i--){
            arr[count++] = matrix[i][startCol];
        }
        startCol++;
    }
    cout<<"Spiral Array : "<<endl;
    for(int i = 0; i<total; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int matrix[4][3];
    cout<<"Enter Array elements : ";
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Given matrix : "<<endl;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    spiralArray(matrix, 4, 3);
}