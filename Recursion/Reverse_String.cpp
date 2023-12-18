#include<iostream>
using namespace std;

void reverseString(string &str, int s, int e) {
    if(s > e)
        return;
    swap(str[s], str[e]);
    s++;
    e--;
    reverseString(str, s, e);
}

int main() {
    string str;
    cout<<"Enter a string : ";
    cin>>str;

    cout<<"Given string : "<<str<<endl;
    reverseString(str, 0, str.length() - 1);
    cout<<"After reverse : "<<str<<endl;
}