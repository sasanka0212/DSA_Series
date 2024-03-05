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

void inorder(vector<node*> &v, node *root) {
    if(root == NULL)
        return;
    inorder(v, root->left);
    if(root->left == NULL && root->right == NULL)
        v.push_back(root);
    inorder(v, root->right);
}

vector<node*> noOfLeafNodes(node *root) {
    vector<node*> v;
    inorder(v, root);
    return v;
}

int main() {
    node *root = NULL;
    root = insertNode(root);

    vector<node*> v;
    v = noOfLeafNodes(root);
    for(node *i : v) 
        cout << i->data << " ";
}