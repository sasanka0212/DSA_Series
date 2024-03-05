#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *insertNode(node *root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter left child of " << root->data << endl;
    root->left = insertNode(root->left);
    cout << "Enter right child of " << root->data << endl;
    root->right = insertNode(root->right);

    return root;
}

int height(node* root){
    if(root == NULL)
        return 0;
        
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left, right) + 1;
    return ans;
}

int main() {
    node *root = NULL;
    root = insertNode(root);

    cout << "Height of tree is " << height(root);
}