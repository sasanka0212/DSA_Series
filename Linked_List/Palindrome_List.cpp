// check a linked list is palindrome or not
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
void print(Node *head) {
    Node *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* reverseList(Node *head) {
    if(head->next == NULL) {
        return head;
    }
    Node *nextHead = reverseList(head->next);
    head->next->next = head;
    return nextHead;
}
bool isPalindrome(Node *head) {
    if(head->next == NULL) {
            return true;
        }
        Node *slow = head;
        Node *fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL)
            slow = slow->next;
        Node *part1 = head;
        Node *part2 = reverseList(slow);
        Node *temp = part2;
        bool flag = true;
        slow->next = NULL;
        while(part1->next!=NULL && part2->next!=NULL) {
            if(part1->data!=part2->data) {
                flag = false;
                break;
            }
            part1 = part1->next;
            part2 = part2->next;
        }
        if(part1->data!=part2->data) {
            flag = false;
        }
        if(part1->next!=NULL) {
            part1->next->next = reverseList(temp);
        }else {
            part1->next = reverseList(temp);
        }
        temp->next = NULL;
        return flag;
}
int main() {
    Node *head = NULL;
    Node *temp = NULL;
    insertHead(head, 2);
    insertHead(head, 4);
    insertHead(head, 1);
    insertHead(head, 4);
    insertHead(head, 2);

    if(isPalindrome(head)) {
        cout<<"Linked list is palindrome" <<endl;
    }else {
        cout<<"Linked list is not palindrome" <<endl;
    }
    return 0;
}