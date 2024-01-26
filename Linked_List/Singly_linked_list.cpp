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
Node* floydDetectLoop(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
Node* getStartLoop(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    Node *startLoop = floydDetectLoop(head);
    if(startLoop == NULL) 
        return NULL;
    Node *slow = head;
    while(slow!=startLoop) {
        slow = slow->next;
        startLoop = startLoop->next;
    }
    return slow;
}
Node* removeLoop(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    Node *start = getStartLoop(head);
    if(start == NULL) 
        return head;
    Node *temp = start;
    while(temp->next!=start) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
int main() {
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertHead(head, 10);
    insertHead(head, 7);
    print(head);
    insertTail(tail, 2);
    insertTail(tail, -4);
    print(head);
    //cout<<head->data<<" "<<tail->data;
    insertMiddle(head, tail, 3, 20);
    insertMiddle(head, tail, 7, 6);
    print(head);
    //cout<<head->data<<" "<<tail->data;
    deleteNode(head, tail, 1);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 3);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 5);
    print(head);
    //creating a loop
    tail->next = head->next;
    if(floydDetectLoop(head)!=NULL) {
        cout<<"Loop is present" <<endl;
    }else {
        cout<<"No loop" <<endl;
    }
    head = removeLoop(head);
    print(head);
    //cout<<head->data<<" "<<tail->data<<endl;
    /*
    deleteNode(head, tail, 1);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 1);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 1);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head, tail, 1);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    */
}