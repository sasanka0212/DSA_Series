#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertTail(Node *&start, Node *&tail, int data) {
    Node *node = new Node(data);
    if(tail == NULL) {
        start = tail = node;
        return;
    }
    tail->next = node;
    tail = node;
}
void print(Node *start) {
    while(start!=NULL) {
        cout<<start->data<<" ";
        start = start->next;
    }
    cout<<endl;
}
Node* middleNode(Node *start) {
    if(start == NULL || start->next == NULL) {
        return start;
    }
    Node *prev = start;
    Node *cur = start;
    while(cur!=NULL && cur->next!=NULL) {
        cur = cur->next->next;
        prev = prev->next;
    }
    return prev;
}
int main() {
    Node *start = NULL;
    Node *tail = NULL;
    insertTail(start, tail, 10);
    insertTail(start, tail, 20);
    insertTail(start, tail, 7);
    insertTail(start, tail, 30);
    //insertTail(start, tail, 19);
    print(start);
    Node *temp = middleNode(start);
    cout<<temp->data<<endl;
}