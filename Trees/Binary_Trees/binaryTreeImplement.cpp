#include<iostream>
#include<queue>
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

void levelOrderTraversal(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //use as a separator

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

int main() {
    node *root = NULL;
    root = insertNode(root);

    // level order traversal
    levelOrderTraversal(root);
}