#include<iostream>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode *root, int data) {
    if(root == NULL) {
        root = new TreeNode(data);
        return root;
    }
    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void createBST(TreeNode *&root) {
    cout << "Enter data : ";
    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data : ";
        cin >> data;
    }
}

void inorder(TreeNode *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void createSortedDLL(TreeNode *root, TreeNode *&head) {
    //base case
    if(root == NULL)
        return;
    createSortedDLL(root->right, head);
    root->right = head;
    if(head) {
        head->left = root;
    }
    head = root;
    createSortedDLL(root->left, head);
}

TreeNode* mergeTwoList(TreeNode *head1, TreeNode *head2) {
    TreeNode *head = NULL;
    TreeNode *tail = NULL;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

void viewDLL(TreeNode *root) {
    while(root) {
        cout << root->data << " ";
        root = root->right;
    }
}

int countNode(TreeNode *head) {
    int count = 0;
    while(head!=NULL) {
        count++;
        head = head->right;
    }
    return count;
}

TreeNode* createBSTFromDLL(TreeNode *&head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }
    TreeNode *leftTree = createBSTFromDLL(head, n/2);
    TreeNode *root = head;
    root->left = leftTree;
    //head changes unique
    head = head->right;
    root->right = createBSTFromDLL(head, n - n/2 - 1);
    return root;
}

int main() {
    cout << "Enter data for 1st BST " << endl;
    TreeNode *root1 = NULL; //tree 1
    createBST(root1);
    cout << endl << "Enter data for 2nd BST " << endl;
    TreeNode *root2 = NULL; //tree 2
    createBST(root2);

    cout << endl << "Inorder traversal of 1st BST: " << endl;
    inorder(root1);

    cout << endl << "Inorder traversal of 2nd BST: " << endl;
    inorder(root2);

    //merge two BST into one
    //step 1 - create sorted DLL for each BST
    TreeNode *head1 = NULL;
    TreeNode *head2 = NULL;
    createSortedDLL(root1, head1);
    head1->left = NULL;
    createSortedDLL(root2, head2);
    head2->left = NULL;

    cout << endl << "1st BST DLL " << endl;
    viewDLL(head1);
    cout << endl << "2nd BST DLL " << endl;
    viewDLL(head2);

    //step 2 - Merge two sorted DLL
    TreeNode *head = mergeTwoList(head1, head2);
    cout << endl << "After merge two DLL " << endl;
    viewDLL(head);

    //step 3 - convert soretd DLL into BST
    TreeNode *root = createBSTFromDLL(head, countNode(head));

    cout << endl << "Inorder of merge BST " << endl;
    inorder(root);
}