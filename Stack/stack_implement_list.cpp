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

class Stack {
    Node *top;
    public:
    Stack() {
        top = NULL;
    }
    // push element
    void push(int data) {
        Node *temp = new Node(data);
        if(!temp) {
            cout << "Stack overflow" << endl;
            return;
        }
        temp->next = top;
        top = temp;
    }
    // pop element
    void pop() {
        if(top == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *del =  top;
        cout << "Deleted element " << del->data << endl;
        top = top->next;
        delete del;
    }
    // check empty or not
    bool isEmpty() {
        return top == NULL;
    }
    // return top element
    int peek() {
        if(!isEmpty()) {
            return top->data;
        }
        return -1;
    }
    // show stack elements
    void display() {
        Node *temp = top;
        while(temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(19);
    s.push(9);
    s.push(-3);

    cout << s.peek() << endl;

    s.pop();
    s.display();
    // check emopty condition
    if(s.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
}