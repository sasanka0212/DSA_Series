#include<iostream>
using namespace std;

class KQueue {
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freeSpot;
    public:
    KQueue(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freeSpot = 0;
        for(int i = 0; i<k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i = 0; i<n-1; i++) {
            next[i] = i + 1;
        }
        next[n-1] = -1;
    }

    void enqueue(int data, int qn) {
        if(freeSpot == -1) {
            cout << "Queue overflow" << endl;
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];
        //check if first element
        if(front[qn-1] == -1) 
            front[qn-1] = index;
        else 
            next[rear[qn-1]] = index;
        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    int dequeue(int qn) {
        if(front[qn-1] == -1) {
            cout <<"Queue underflow" << endl;
            return -1;
        }
        int index = front[qn-1];
        int element = arr[index];
        if(front[qn-1] == rear[qn-1]) 
            rear[qn-1] = next[index];
        front[qn-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return element;
    }

    bool isEmpty(int qn) {
        return (front[qn-1] == -1) ? true : false;
    }

    int qFront(int qn) {
        return (front[qn-1] == -1) ? -1 : arr[front[qn-1]];
    }
};

int main() {
    KQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(19, 3);
    q.enqueue(6, 2);
    q.enqueue(20, 1);

    cout << q.qFront(1) << endl;
    cout << q.qFront(2) << endl; 
    cout << q.qFront(3) << endl;

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
}