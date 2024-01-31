// clone list approach 1
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printRandom(Node *head)
{
    while (head != NULL)
    {
        if (head->arb != NULL)
        {
            cout << head->data << " " << head->arb->data << endl;
        }
        head = head->next;
    }
    cout << endl;
}
void insertTail(Node *&cloneHead, Node *&cloneTail, int data)
{
    Node *newnode = new Node(data);
    if (cloneHead == NULL)
    {
        cloneHead = cloneTail = newnode;
        return;
    }
    cloneTail->next = newnode;
    cloneTail = newnode;
}
Node *copyList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    // insert clone nodes in between original nodes
    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *cur1 = originalNode->next;
        Node *cur2 = cloneNode->next;
        originalNode->next = cloneNode;
        cloneNode->next = cur1;
        originalNode = cur1;
        cloneNode = cur2;
    }
    originalNode = head;
    while (originalNode != NULL && originalNode->next != NULL)
    {
        if (originalNode->arb != NULL)
            originalNode->next->arb = originalNode->arb->next;
        originalNode = originalNode->next->next;
    }
    // revert changes
    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if (originalNode != NULL)
            cloneNode->next = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    insertTail(head, tail, 4);
    insertTail(head, tail, 5);
    print(head);

    // adding random pointers
    // 1,3
    head->arb = head->next->next;
    // 3,5
    head->next->next->arb = head->next->next->next->next;
    // 4,3
    head->next->next->next->arb = head->next->next;
    // 5,2
    head->next->next->next->next->arb = head->next;
    printRandom(head);

    // creating clone linked list with next and random pointers
    Node *cloneHead = copyList(head);
    cout << "Clone linked list : " << endl;
    print(cloneHead);
    printRandom(cloneHead);
}