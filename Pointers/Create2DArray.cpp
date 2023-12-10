#include<iostream>
using namespace std;

int main() {
    int row, col; 
    cout<<"Enter row & column : ";
    cin>>row>>col;

    int **arr = new int*[row];
    for(int i = 0; i<row; i++) {
        arr[i] = new int[col];
    }
    cout<<"Enter elements : "<<endl;
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"Given elements :"<<endl;
    for(int i = 0; i<row; i+=1) {
        for(int j = 0; j<col; j+=1) {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}