#include<iostream>
#include<stack>
using namespace std;bool isSame(char ch, char top) { 
    if ((top == '{' && ch == '}') || 
        (top == '[' && ch == ']') ||
        (top == '(' && ch == ')')) {
            return true;
    }
    return false;
}
bool isValidParenthesis(string s)
{
    stack<char> res;
    for(int i = 0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            res.push(ch);
        } else {
            if(!res.empty()) {
                if(isSame(ch, res.top())) {
                    res.pop();
                } else{
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }  
    return res.empty(); 
}

int main() {
    string s = "[{()]";
    if(isValidParenthesis(s)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Not valid parentheses" << endl;
    }
}