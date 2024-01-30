#include<iostream>
using namespace std;
template <typename T>
class Node {
    public:
    T data;
    Node *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertHead(Node<int> *&head, int data) {
    Node<int> *node = new Node<int>(data);
    node->next = head;
    head = node;
}
void insertTail(Node<int> *&tail, int data) {
    Node<int> *node = new Node<int>(data);
    tail->next = node;
    tail = node;
}
void print(Node<int> *head) {
    Node<int> *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node<int>* solve(Node<int> *first, Node<int> *second) {
    Node<int> *cur1 = first;
    Node<int> *next1 = cur1->next;
    Node<int> *cur2 = second;

    while(next1!=NULL && cur2!=NULL) {
        if(cur2->data>=cur1->data && cur2->data<=next1->data) {
            Node<int> *temp = cur2->next;
            cur1->next = cur2; 
            cur2->next = next1;
            cur1 = cur2;
            cur2 = temp;
        }else {
            cur1 = next1;
            next1 = next1->next;
        }
    }

    if(next1 == NULL) {
        cur1->next = cur2;
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }
    if(first->data <= second->data) {
        return solve(first, second);
    }
    else {
        return solve(second, first);
    }
}
int main() {
    //creation of 1st sorted list
    Node<int> *head1 = NULL;
    Node<int> *tail1 = NULL;
    insertHead(head1, 30);
    insertHead(head1, 20);
    insertHead(head1, 5);
    print(head1);

    //created of 2nd sorted list
    Node<int> *head2 = NULL;
    Node<int> *tail2 = NULL;
    insertHead(head2, 25);
    insertHead(head2, 16);
    insertHead(head2, 10);
    insertHead(head2, 7);
    print(head2);

    Node<int> *head = sortTwoLists(head1, head2);
    print(head);    
}