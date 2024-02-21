#include<iostream>
using namespace std;

class Deque
{
    int *arr;
    int size;
    int front, rear;
    public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if((rear + 1) % size == front) {
            return false;
        } 
        else {
            if(front == -1) {
                front = rear = 0;
            } else if(front == 0){
                front = size - 1;
            } else {
                front--;
            }
            arr[front] = x;
            return true;
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if((rear + 1) % size == front) {
            return false;
        } else {
            if(rear == -1) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            arr[rear] = x;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front == -1)
            return -1;
        else {
            int d = arr[front];
            if(front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return d;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        
        if(rear == -1) 
            return -1;
        else {
            int d = arr[rear];
            if(front == rear) {
                front = rear = -1;
            } else if(rear == 0){
                rear = size - 1;
            } else {
                rear--;
            }
            return d;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        return (front == -1) ? -1 : arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        return (rear == -1) ? -1 : arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return (front == -1) ? true : false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return ((rear + 1) % size == front) ? true : false;
    }
};

int main() {
    Deque d(10);

    cout << d.isEmpty() << endl;
    cout << d.pushFront(10) << endl;
    cout << d.pushFront(20) << endl;
    cout << d.pushRear(30) << endl;
    cout << d.getFront() << endl;
    cout << d.popRear() << endl;
    cout << d.popRear() << endl;

}