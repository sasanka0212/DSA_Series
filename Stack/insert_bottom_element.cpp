#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s, int element) {
    if(s.empty()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    insertBottom(s, element);
    s.push(num);
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(8);
    s.push(7);
    s.push(6);

    insertBottom(s, 19);
    while(!s.empty()) {
        cout << s.top() << endl; 
        s.pop();
    }
}