#include<iostream>
using namespace std;

char toLowerCase(char c) {
    char ch = (c >= 'a' && c <= 'z') ? c : c - 'A' + 'a';
    return ch;
}

bool valid(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

bool checkPalindrome(string s) {
    int i = 0, j = s.length()-1;
    while(i<j) {
        if(valid(s[i]) && valid(s[j])) { 
            if(toLowerCase(s[i]) != toLowerCase(s[j])) {
                return false;
            } else {
                i++;
                j--;
            } 
        } else {
            if(valid(s[i])) 
                j--;
            else
                i++;
        }
    }
    return true;
}

int main(){
    string s = "c1 O$d@eeD o1c";

    cout << "Pakindrome or not :" << checkPalindrome(s);
}