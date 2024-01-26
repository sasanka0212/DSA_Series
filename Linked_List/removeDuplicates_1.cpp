#include<iostream>
#include<map>
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
/*Node *removeDuplicates(Node *head)
{
    if(head == NULL) {
        return NULL;
    }
    Node *temp = head;
    while(temp!=NULL && temp->next!=NULL) {
        Node *cur = temp->next;
        Node *prev = temp;
        while(cur!=NULL) {
            if(temp->data == cur->data) {
                Node *nodeToDelete = cur;
                cur = cur->next;
                prev->next = cur;
                delete nodeToDelete;
            }else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        temp = temp->next;
    }
    return head;
}*/
Node *removeDuplicates(Node *head)
{
    if(head == NULL) {
        return NULL;
    }
    map<int, bool> visited;
    Node *cur = head;
    Node *prev = NULL;
    while(cur!=NULL) {
        if(visited[cur->data] == true) {
            Node *nodeToDelete = cur;
            cur = cur->next;
            prev->next = cur;
            delete nodeToDelete;
            continue;
        }
        visited[cur->data] = true;
        prev = cur;
        cur = cur->next;
    }
    return head;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL; 
    insertHead(head, 4);
    insertHead(head, 5);
    insertHead(head, 2);
    insertHead(head, 4);
    insertHead(head, 4);
    insertHead(head, 6);
    insertHead(head, 5);
    print(head);
    head = removeDuplicates(head);
    print(head);
}