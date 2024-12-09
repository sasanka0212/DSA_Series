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

void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s, num);
}

void display(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } 
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(10);
    s.push(-3);
    s.push(19);
    s.push(6);
    s.push(11);
    display(s);

    reverseStack(s);

    display(s);
}