#include<iostream>
#include<vector>
using namespace std;

void possibleSubsequence(vector<string> &ans, string str, string output, int index) {
    if(index == str.length()) {
        if(!output.empty())
            ans.push_back(output);
        return;
    }
    //excluding letter
    possibleSubsequence(ans, str, output, index + 1);
    //including letter
    output = output + str[index];
    possibleSubsequence(ans, str, output, index + 1); 
}

int main() {
    string str = "abc";
    vector<string> ans;
    string output = "";
    possibleSubsequence(ans, str, output, 0);
    for(string s : ans) {
        cout<<s<<endl;
    }
}