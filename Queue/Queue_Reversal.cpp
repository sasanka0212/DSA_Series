#include<iostream>
#include<queue>
using namespace std;

void display(deque<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
}

void reverseQueue(deque<int> &q) {
    if(q.empty()) 
        return;
    int v = q.front();
    q.pop_front();
    reverseQueue(q); 
    q.push_back(v);
}

int main() {
    deque<int> q;
    q.push_back(10);
    q.push_back(12);
    q.push_back(19);
    q.push_back(6);
    q.push_back(101);

    display(q);

    cout << "Reverse of the queue " << endl;
    reverseQueue(q);

    display(q);
}