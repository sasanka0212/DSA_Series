#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int x) {
    if(stack.empty()) {
        stack.push(x);
        return;
    }
    int n = stack.top();
    stack.pop();
    insertAtBottom(stack, x);
    stack.push(n);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    int n = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, n);
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