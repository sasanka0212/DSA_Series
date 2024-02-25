#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void interpolation(queue<int> &q) {
    int n = q.size();
    stack<int> s;
    for(int i = 0; i<n/2; i++) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for(int i = 0; i<n/2; i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    for(int i = 0; i<n/2; i++) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(14);
    q.push(17);
    q.push(21);
    q.push(22);
    q.push(19);
    q.push(6);
    q.push(18);

    cout << "Befor interpolation " << endl;
    display(q);
    interpolation(q);

    cout << "After interpolation " << endl;
    display(q);
}