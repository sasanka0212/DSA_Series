#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int x) {
	if(s.empty() || x > s.top()) {
		s.push(x);
		return;
	}
	int n = s.top();
	s.pop();
	sortedInsert(s, x);
	s.push(n);
} 

void sortStack(stack<int> &s) {
	if(s.empty()) 
		return;
	
	//save top element
	int n = s.top();
	s.pop();
	sortStack(s);
	sortedInsert(s, n);
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