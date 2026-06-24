#include <iostream>
#include <climits>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool isValidBST(node* root, long min, long max) {
    if (root == NULL)
        return true;
     if (root->val <= min || root->val >= max)
        return false;
    bool IsleftValid= isValidBST(root->left, min, root->val);
    bool IsrightValid= isValidBST(root->right, root->val, max);
    return IsleftValid && IsrightValid;
}
int main() {
    node* root = new node(2);
    root->left = new node(1);
    root->right = new node(3);

    if (isValidBST(root,LONG_MIN, LONG_MAX))
        cout << "Valid BST" << endl;
    else
        cout << "Not a Valid BST" << endl;

    return 0;
}