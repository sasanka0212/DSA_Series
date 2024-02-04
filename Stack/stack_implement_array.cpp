#include<iostream>
using namespace std;

class stack {
    int *arr;
    int top;
    int size;
    public:
    stack(int size) {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }
    void push(int data) {
        if(top < size - 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    void pop() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Deleted element " << arr[top];
        top--;
    }
    int peek() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top];
    }
    void show() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        for(int i = top; i>=0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    stack st(5);
    st.push(5);
    st.push(7);
    st.push(1);
    st.push(19);

    cout << st.peek() << endl;
    st.show();
}