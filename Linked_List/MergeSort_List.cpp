#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertTail(node *&head, node *&tail, int data) {
    node *newnode = new node(data);
    if(head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
node* sortList(node *first, node *second) {
    if(first->next == NULL) {
        first->next = second;
        return first;
    }
    node *prev = first;
    node *cur1 = first->next;
    node *cur2 = second;
    while(cur1!=NULL && cur2!=NULL) {
        if(cur2->data >= prev->data && cur2->data <= cur1->data) {
            node *temp = cur2->next;
            prev->next = cur2;
            cur2->next = cur1;
            prev = cur2;
            cur2 = temp;
        } else {
            prev = cur1;
            cur1 = cur1->next;
        }
    }
    if(cur1 == NULL) {
        prev->next = cur2;
    }
    return first;
}
node* merge(node *first, node *second) {
    if(first->data <= second->data) {
        return sortList(first, second);
    } else {
        return sortList(second, first);
    }
}
node* mergeSort(node *head) {
    if(head->next == NULL) {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *part1 = head;
    node *part2 = slow->next;
    slow->next = NULL;
    part1 = mergeSort(part1);
    part2 = mergeSort(part2);
    head = merge(part1, part2);
    return head;
}
void print(node *head) {
    while(head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    node *head = NULL;
    node *tail = NULL;
    insertTail(head, tail, 5);
    insertTail(head, tail, 20);
    insertTail(head, tail, 10);
    insertTail(head, tail, 30);
    insertTail(head, tail, 2);
    print(head);
    head = mergeSort(head);
    print(head);
}