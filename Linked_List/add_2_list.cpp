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

Node* createList(Node *head) {
    int data;
    cout << "Enter data:" << endl;
    cin >> data;
    if(data == -1) 
        return NULL;
    Node *newNode = new Node(data);
    newNode->next = createList(newNode);
    return newNode;
}

void reverseList(Node *&head, Node *prev, Node *cur) {
    if(cur == NULL) {
        head = prev;
        return;
    }
    reverseList(head, cur, cur->next);
    cur->next = prev;
}

Node* addTwoList(Node *head1, Node *head2) {
    Node *head = new Node(-1);
    Node *temp = head;
    int c = 0;
    while(head1!=NULL && head2!=NULL) {
        int d = (c + head1->data + head2->data)%10;
        c = (c + head1->data + head2->data)/10;
        Node *newNode = new Node(d);
        temp->next = newNode;
        temp = newNode;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1!=NULL) {
        int d= (c + head1->data) % 10;
        c= (c + head1->data) / 10;
        Node *newNode = new Node(d);
        temp->next = newNode;
        temp = newNode;
        head1 = head1->next;
    }
    while(head2!=NULL) {
        int d= (c + head2->data) % 10;
        c= (c + head2->data) / 10;
        Node *newNode = new Node(d);
        temp->next = newNode;
        temp = newNode;
        head2 = head2->next;
    }
    while(c != 0) {
        Node *newNode = new Node(c);
        temp->next = newNode;
        temp = newNode;
    }
    return head->next;
}

void print(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    head1 = createList(head1);
    head2 = createList(head2);
    print(head1);
    print(head2);

    reverseList(head1, NULL, head1);
    reverseList(head2, NULL, head2);
    print(head1);
    print(head2);

    Node *head3 = addTwoList(head1, head2);
    print(head3);
    reverseList(head3, NULL, head3);
    print(head3);
}