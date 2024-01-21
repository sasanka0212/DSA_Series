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
    ~Node() {
        cout<<"Deleted Data : "<<data<<endl;
    }
};
void insertNode(Node *&tail, int v, int data) {
    if(tail == NULL) {
        Node *node = new Node(data);
        node->next = node;
        tail = node;
        return;
    }
    Node *temp = tail;
    while(temp->data != v) {
        temp = temp->next;
    }
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
}
void deleteNode(Node *&tail, int v) {
    Node *cur = tail->next;
    Node *prev = tail;
    while(cur->data!=v) {
        prev = cur;
        cur = cur->next;
    }
    if(cur->next == cur) {
        cur->next = NULL;
        tail = NULL;
        delete cur;
        return;
    }
    prev->next = cur->next;
    if(cur == tail) {
        tail = prev;
    }
    cur->next = NULL;
    delete cur;
}
void print(Node *tail) {
    if(tail == NULL) {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    Node *temp = tail;
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=tail);
    cout<<endl;
}
//to check linked list is either circular or not
bool isCircular(Node *head) {
    if(head == NULL) {
        return true;
    }
    Node *temp = head->next;
    while(temp!=NULL && temp!=head) {
        temp = temp->next;
    }
    if(temp == NULL) {
        return false;
    }
    return true;
}
int main() {
    Node *tail = NULL;
    insertNode(tail, 2, 17);
    insertNode(tail, 17, 19);
    insertNode(tail, 17, 2);
    cout<<tail->data<<endl;
    print(tail);
    insertNode(tail, 19, 7);
    print(tail);
    //deleteNode(tail, 2);
    //print(tail);
    deleteNode(tail, 17);
    print(tail);
    //deleteNode(tail, 19);
    //print(tail);
    //Node *temp = tail;
    //tail = tail->next;
    //temp->next = NULL;
    if(isCircular(tail)) {
        cout<<"Linked list is circular"<<endl;
    }else {
        cout<<"Linked list is not circular"<<endl;
    }
}