#include<iostream>
using namespace std;

bool isPalindrome(string str, int s) {
    int e = str.length() - 1 - s;
    if(s > e)
        return true;
    if(str[s] != str[e])
        return false;
    return isPalindrome(str, s + 1);
}

int main() {
    string str;
    cout<<"Enter a string : ";
    cin>>str;

    if(isPalindrome(str, 0))
        cout<<"Given string is palindrome"<<endl;
    else
        cout<<"Given string is not palindrome"<<endl;
}