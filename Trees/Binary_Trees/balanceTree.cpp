#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* insertNode(node *root) {
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new node(data);
    if(data == -1) 
        return NULL;
    
    cout << "Enter left child of " << root->data << endl;
    root->left = insertNode(root->left);
    cout << "Enter right child of " << root->data << endl;
    root->right = insertNode(root->right);
    return root;
}

void levelOrderTraverse(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        } else {
            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

pair<bool, int> checkBalanced(node *root) {
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = checkBalanced(root->left);
    pair<bool, int> right = checkBalanced(root->right);
    int lHeight = left.second;
    int rHeight = right.second;
    pair<bool, int> ans;
    ans.second = max(lHeight, rHeight) + 1;
    if(abs(lHeight - rHeight) <= 1 && left.first && right.first) {
        ans.first = true;
    } else {
        ans.first = false;
    }
    return ans;
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(node *root)
{
    pair<bool, int> ans = checkBalanced(root);
    return ans.first;
}
int main() {
    node *root = insertNode(root);
    levelOrderTraverse(root);

    if(isBalanced(root))
        cout << "Tree is balanced" << endl;
    else 
        cout << "Tree is not balanced" << endl; 
}