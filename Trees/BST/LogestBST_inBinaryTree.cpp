#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

TreeNode<int>* insertNode(TreeNode<int> *root) {
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new TreeNode<int>(data);
    if(data == -1) {
        return NULL;
    }
    cout << "Enter left child of " << root->data << endl;
    root->left = insertNode(root->left);
    cout << "Enter right child of " << root->data << endl;
    root->right = insertNode(root->right);
    return root;
} 

void inorder(TreeNode<int> *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrderTraversal(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);   //single ended queue
    q.push(NULL);

    while(!q.empty()) {
        TreeNode<int> *temp = q.front();
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

Info solve(TreeNode<int> *root, int &ans) {
    if(root == NULL) {
        return {INT_MAX, INT_MIN, true, 0};
    }
    //recursive calls
    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info curNode;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = min(root->data, left.mini);
    curNode.size = left.size + right.size + 1;

    //check valid BST or not
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        curNode.isBST = true;
    } else {
        curNode.isBST = false;
    }

    //update maxSize
    if(curNode.isBST) {
        ans = max(ans, curNode.size);
    }
    return curNode;
}
int largestBST(TreeNode<int> *root){
    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}

int main() {
    TreeNode<int> *root = NULL;
    root = insertNode(root);

    levelOrderTraversal(root);
    inorder(root);

    cout << "Length of largest BST : " << largestBST(root);
}