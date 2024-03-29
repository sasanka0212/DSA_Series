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

Node* inorderPredecessor(Node *root) {
    if(root->right == NULL) {
        return root;
    }
    return inorderPredecessor(root->right);
}

Node* deletefromBST(Node *root, int val) {
    //base case
    if(root == NULL)
        return root;
    
    //base case 2
    if(root->data == val) {
        //0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //1 child
        //only left child exists
        if(root->left && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //only right child exists
        if(root->left == NULL && root->right) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //2 child exists
        if(root->left && root->right) {
            int maxVal = inorderPredecessor(root->left)->data;
            root->data = maxVal;
            root->left = deletefromBST(root->left, maxVal);
            return root;
        }
    }
    if(val > root->data) {
        root->right = deletefromBST(root->right, val);
        return root;
    } else {
        root->left = deletefromBST(root->left, val);
        return root;
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

    root = deletefromBST(root, 15);

    cout << endl << "Level order traversal " << endl;
    levelOrderTraversal(root);
}