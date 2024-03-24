#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node *root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void createBST(Node *&root) {
    cout << "enter data : ";
    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data : ";
        cin >> data;
    }
}

void levelOrderTraversal(Node *&root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *temp = q.front();
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

void inorder(Node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    createBST(root);

    //10 7 20 15 6 8 17 -1

    cout << endl << "Level order traversal " << endl;
    levelOrderTraversal(root);

    cout << endl << "Inorder traversal " << endl;
    inorder(root);
}