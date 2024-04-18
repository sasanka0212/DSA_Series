#include<iostream>
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

void inorder(node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void morrisTraversal(node *&root) {
    node *currentNode = root;
    while(currentNode != NULL) {
        if(currentNode->left == NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->right;
        } else {
            node *predecessor = currentNode->left;
            while(predecessor->right != NULL && predecessor->right != currentNode) {
                predecessor = predecessor->right;
            }
            //break when precessor is find out successfully
            if(predecessor->right) {
                cout << currentNode->data << " ";
                currentNode = currentNode->right;
            } else {
                predecessor->right = currentNode;
                currentNode = currentNode->left;
            }
        }
    }
}

int main() {
    node *root = insertNode(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 

    // levelorderTraversal(root);
    cout << "Inorder traversal " << endl;
    inorder(root);

    cout << "Morris Traversal " << endl;
    morrisTraversal(root);
}