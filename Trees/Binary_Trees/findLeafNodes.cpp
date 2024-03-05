#include<iostream>
#include<vector>
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
    cout << "Enter left child for " << root->data << endl;
    root->left = insertNode(root->left);
    cout << "Enter right child for " << root->data << endl;
    root->right = insertNode(root->right);
    return root;
}

void inorder(node *root, int &count) {
    if(root == NULL)
        return;
    inorder(root->left, count);
    if(root->left == NULL && root->right == NULL)
        count++;
    inorder(root->right, count);
}

int noOfLeafNodes(node *root) {
    int count = 0;
    inorder(root, count);
    return count;
}

int main() {
    node *root = NULL;
    root = insertNode(root);

    vector<node*> v;
    cout << "No of leaf nodes : " << noOfLeafNodes(root);
}