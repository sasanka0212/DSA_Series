#include<iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;
    public:
    TwoStack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    // push in stack 1
    void push1(int num) {
        if(top1 == top2 - 1) {
            return;
        }
        top1++;
        arr[top1] = num;
    }
    // Push in stack 2.
    void push2(int num) {
        if(top2 == top1 + 1) {
            return;
        }
        top2--;
        arr[top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0) {
            int v = arr[top1--];
            return v;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size) {
            int v = arr[top2++];
            return v;
        }
        return -1;
    }
    // peek of stack1
    int peek1() {
        if(top1 == -1) {
            return -1;
        }
        return arr[top1];
    }
    // peek of top2
    int peek2() {
        if(top2 == size) {
            return -1;
        }
        return arr[top2];
    }
};

int main() {
    TwoStack ts(10);

    // push in stack1
    ts.push1(30);
    ts.push1(19);
    ts.push1(20);

    //push in stack2
    ts.push2(5);
    ts.push2(48);
    ts.push2(37);

    cout << ts.peek1() << endl;
    cout << ts.peek2() << endl;
}