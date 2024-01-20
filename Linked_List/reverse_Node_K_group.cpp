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
Node* kReverse(Node *head, int k) {
    if(head == NULL) {
        return head;
    }
    Node *cur = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int count = 0;
    while(count < k && cur!=NULL) {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
        count++;
    }
    if(forward!=NULL) {
        head->next = kReverse(forward, k);
    }
    return prev;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail, 7);
    insertTail(head, tail, 30);
    insertTail(head, tail, 19);
    insertTail(head, tail, 6);
    print(head);
    head = kReverse(head, 4);
    print(head);
}