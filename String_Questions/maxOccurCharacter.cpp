// most occur character in a string

#include<iostream>
#include<vector>
using namespace std;

char mostOccurChar(string s){
    vector<int> count(26,0);
    for(int i = 0; i<s.length(); i++){
        int n;
        if(s[i]>='a' && s[i]<='z'){
            n = s[i] - 'a';
        }else{
            n = s[i] - 'A';
        }
        count[n] = count[n] + 1;
    }
    int max = -1, index = 0;
    for(int i = 0; i<count.size(); i++){
        if(max < count[i]){
            max = count[i];
            index = i;
        }
    }

    return 'a' + index;
}

int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;

    cout<<"Most occur character is : "<<mostOccurChar(s);
    return 0;
}