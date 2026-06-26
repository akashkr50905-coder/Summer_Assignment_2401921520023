#include<iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

bool helper(node* left, node* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    if(left->val == right->val){
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    else return false;
}

bool isSymmetric(node* root){
    return helper(root->left, root->right);
}

int main(){
    // tree: [1,2,2,3,4,4,3]
    node* root             = new node(1);
    root->left             = new node(2);
    root->right            = new node(2);
    root->left->left       = new node(3);
    root->left->right      = new node(4);
    root->right->left      = new node(4);
    root->right->right     = new node(3);

    if(isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is not Symmetric" << endl;

    return 0;
}