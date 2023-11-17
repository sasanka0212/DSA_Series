#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
    int s = 0, e = v.size() - 1;
    while(s<e){
        swap(v[s], v[e]);
        s+=1;
        e-=1;
    }
    return v;
}

vector<int> addArrays(vector<int> num1, vector<int> num2){
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    vector<int> ans;
    while(i>=0 && j>=0){
        int sum = num1[i] + num2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i-=1;
        j-=1;
    }
    while(i>=0){
        int sum = num1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i-=1;
    }
    while(j>=0){
        int sum = num2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j-=1;
    }
    if(carry!=0){
        ans.push_back(carry);
    }
    return reverse(ans);
}

int main(){
    vector<int> arr1 = {9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9};

    vector<int> ans = addArrays(arr1, arr2);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}