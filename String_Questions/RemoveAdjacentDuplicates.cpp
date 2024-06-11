//Remove all adjacent duplicates in a string
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        temp.push_back(s[0]);
        int j = 1;
        for(int i = 1; i<s.length(); i++){
            temp.push_back(s[i]);
            if(j>0 && temp[j]==temp[j-1]){
                temp.erase(j-1, 2);   
                j--;
            }else{
                j++;
            }
        }
        return temp;
    }
};

int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    Solution S;
    cout<<"After removing all adjacent duplicates : "<<S.removeDuplicates(str);
    return 0;
}