#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int count, int n) {
    if(count == n/2) {
        s.pop();
        return;
    }
    count++;
    int c = s.top();
    s.pop();
    solve(s, count, n);
    s.push(c);
}

void removeElement(stack<int> &s, int n) {
    int count = 0;
    solve(s, count, n);
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(19);

    removeElement(s, s.size());
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}