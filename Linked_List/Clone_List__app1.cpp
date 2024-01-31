// clone list approach 1
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *arb;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};
void print(Node *head) {
    while(head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printRandom(Node *head) {
    while(head != NULL) {
        if(head->arb != NULL) {
            cout << head->data << " " << head->arb->data << endl;
        }
        head = head->next;
    }
    cout << endl;
}
void insertTail(Node *&head, Node *&tail, int data) {
    Node *newnode = new Node(data);
    if(head == NULL) {
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
Node *copyList(Node *head)
{
    Node *clone = NULL;
    Node *tail = NULL;
    Node *temp = head;
    //map<Node*, Node*> visit;
    while(temp != NULL) {
        insertTail(clone, tail, temp->data);
        //visit[temp] = tail;
        temp = temp->next;
    }
    temp = head;
    tail = clone;
    while(temp != NULL) {
        Node *cur = temp->arb;
        temp = temp->next;
        tail->arb = cur;
        tail = tail->next;
    }
    return clone;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    insertTail(head, tail, 4);
    insertTail(head, tail, 5);
    print(head);

    //adding random pointers
    //1,3
    head->arb = head->next->next;
    //3,5
    head->next->next->arb = head->next->next->next->next;
    //4,3
    head->next->next->next->arb = head->next->next;
    //5,2
    head->next->next->next->next->arb = head->next;
    printRandom(head);

    //creating clone linked list with next and random pointers
    Node *cloneHead = copyList(head);
    cout << "Clone linked list : " <<endl;
    print(cloneHead);
    printRandom(cloneHead);
}