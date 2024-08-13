// letter combination of a phone keypad number
#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, int index, string output, vector<string> &ans, string nums[]) {
    if(index == digits.length()) {
        ans.push_back(output);
        return;
    }
    int n = digits[index] - '0';
    string value = nums[n];
    for(int i = 0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, index + 1, output, ans, nums);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0) 
        return ans;
    string output = "";
    string nums[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", 
                    "pqrs", "tuv", "wxyz"};
    solve(digits, 0, output, ans, nums);
    return ans;
}

int main() {
    string digits = "3524";
    vector<string> ans = letterCombinations(digits);
    for(string s : ans) {
        cout<<s<<endl;
    }
    return 0;
}