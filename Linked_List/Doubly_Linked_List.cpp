#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node() {
        cout<<"Deleted data : "<<data<<endl;
    }
};
void insertHead(Node *&head, Node *&tail, int data) {
    Node *node = new Node(data);
    if(head == NULL) {
        head = tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}
void insertTail(Node *&head, Node *&tail, int data) {
    Node *node = new Node(data);
    if(tail == NULL) {
        head = tail = node;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
}
void insertPosition(Node *&head, Node *&tail, int pos, int data) {
    if(pos == 1) {
        insertHead(head, tail, data);
        return;
    }
    Node *temp = head;
    while(pos > 2) {
        temp = temp->next;
        pos--;
    }
    Node *node = new Node(data);
    node->prev = temp;
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
}
void deleteNode(Node *&head, Node *&tail, int pos) {
    if(pos == 1) {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        if(head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }
    Node *prev = head;
    Node *cur = head->next;
    while(pos > 2) {
        prev = cur;
        cur = cur->next;
        pos--;
    }
    prev->next = cur->next;
    if(cur->next == NULL) {
        tail = prev;
    }else {
        cur->next->prev = prev;
    }
    cur->prev = cur->next = NULL;
    delete cur;
}
void print(Node *head) {
    if(head == NULL) {
        cout<<"Linked list is empty..."<<endl;
        return;
    }
    Node *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insertHead(head, tail, 10);
    insertHead(head, tail, 19);
    insertTail(head, tail, 11);
    print(head);
    //deleteNode(head, tail, 1);
    cout<<head->data<<" "<<tail->data<<endl;
    insertPosition(head, tail, 2, 20);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 4);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 2);
    deleteNode(head, tail, 2);
    deleteNode(head, tail, 1);
    print(head);
}