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

//Insert from level order
void insertFromLevelOrder(node *&root) {
    queue<node*> q;
    int data;
    cout << "Enter data of root : ";
    cin >> data;
    root = (data == -1) ? NULL : new node(data);
    q.push(root);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();

        if(temp != NULL) {
            int leftChild;
            cout << "Enter left child value of " << temp->data << " : ";
            cin >> leftChild;
            temp->left = (leftChild == -1) ? NULL : new node(leftChild);
            q.push(temp->left);

            int rightChild;
            cout << "Enter right child value of " << temp->data << " : ";
            cin >> rightChild;
            temp->right = (rightChild == -1) ? NULL : new node(rightChild);
            q.push(temp->right);
        }
    }
}

//Inorder Traversal
void inorderTraversal(node *root) {
    if(root == NULL) 
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

//Preorder traversal
void preorderTraversal(node *root) {
    if(root == NULL) 
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Postorder Traversal
void postorderTraversal(node *root) {
    if(root == NULL) 
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    node *root = NULL;
    //root = insertNode(root);
    insertFromLevelOrder(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    // level order traversal
    cout << endl << "Level order Traversal : " << endl;
    levelOrderTraversal(root);

    cout << endl << "Inorder traversal : " << endl;
    inorderTraversal(root);

    cout << endl << "Preorder Traversal : " << endl;
    preorderTraversal(root);

    cout << endl << "Postorder Traversal : " << endl;
    postorderTraversal(root);
}