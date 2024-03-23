#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertNode(Node *root) {
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new Node(data);
    if(data == -1)
        return NULL;
    cout << "Enter left child of " << root->data << endl;
    root->left = insertNode(root->left);
    cout << "Enter right child of " << root->data << endl;
    root->right = insertNode(root->right);
    return root;
}

void solve(Node *root, int &maxSum, int &maxLength, int len, int sum) {
    if(root == NULL) {
        if(len > maxLength) {
            maxLength = len;
            maxSum = sum;
        } else if(len == maxLength) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    solve(root->left, maxSum, maxLength, len + 1, sum + root->data);
    solve(root->right, maxSum, maxLength, len + 1, sum + root->data);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLength = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    
    solve(root, maxSum, maxLength, len, sum);
    return maxSum;
}

int main() {
    Node *root = insertNode(root);
    int ans = sumOfLongRootToLeafPath(root);

    cout << "Sum of longest root : " << ans; 
}