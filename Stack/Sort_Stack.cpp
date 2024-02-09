#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int data) {
	if(stack.empty() || stack.top() <= data) {
		stack.push(data);
		return;
	}
	int top = stack.top();
	stack.pop();
	sortedInsert(stack, data);
	stack.push(top);
} 
void sortStack(stack<int> &stack)
{
	if(stack.empty()) {
		return;
	}
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, top);
}

void display(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } 
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(19);
    s.push(-5);
    s.push(6);
    s.push(21);
    s.push(0);

    display(s);

    sortStack(s);

    display(s);
}