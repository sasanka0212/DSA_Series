#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    //constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node() {
        cout<<"Deleted data : "<<this->data<<endl;
        this->next = NULL;
    }
};
void insertHead(Node *&head, int data) {
    Node *node = new Node(data);
    node->next = head;
    head = node;
}
void insertTail(Node *&tail, int data) {
    Node *node = new Node(data);
    tail->next = node;
    tail = node;
}
void deleteNode(Node *&head, Node *&tail, int pos) {
    if(pos == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node *cur = head;
        Node *prev = NULL;
        while(pos>1) {
            prev = cur;
            cur = cur->next;
            pos--;
        }
        prev->next = cur->next;
        if(cur->next == NULL) {
            tail = prev;
        }
        delete cur;
    }
}
void insertMiddle(Node *&head, Node *&tail, int pos, int data) {
    if(pos == 1) {
        insertHead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while(count < pos-1) {
        temp = temp->next;
        count++;
    }
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
    if(node->next == NULL) {
        tail = node;
    }
}
void print(Node *&head) {
    Node *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertTail(Node *&tail, Node *temp) {
    tail->next = temp;
    tail = temp;
}
// Approach 1 to sort list of 0s, 1s and 2s
Node* sortList(Node *head){
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;
    while(temp!=NULL) {
        if(temp->data == 0) {
            insertTail(zeroTail, temp);
        }else if(temp->data == 1) {
            insertTail(oneTail, temp);
        }else {
            insertTail(twoTail, temp);
        }
        temp = temp->next;
    }
    if(oneHead->next!=NULL) {
        zeroTail->next = oneHead->next;
    }else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL; 
    insertHead(head, 0);
    insertHead(head, 1);
    insertHead(head, 0);
    insertHead(head, 2);
    insertHead(head, 0);
    insertHead(head, 2);
    insertHead(head, 1);
    print(head);
    head = sortList(head);
    cout<<"After sorting :" <<endl;
    print(head);
}