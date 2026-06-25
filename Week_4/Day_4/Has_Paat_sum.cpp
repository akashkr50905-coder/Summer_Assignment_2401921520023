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

bool helper(node* root, int targetSum, int currSum){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL && currSum + root->val == targetSum) return true;
    return helper(root->left,  targetSum, currSum + root->val) ||
           helper(root->right, targetSum, currSum + root->val);
}

bool hasPathSum(node* root, int targetSum){
    return helper(root, targetSum, 0);
}

int main(){
    // tree: [5,4,8,11,null,13,4,7,2,null,null,null,1]
    node* root      = new node(5);
    root->left      = new node(4);
    root->right     = new node(8);
    root->left->left        = new node(11);
    root->right->left       = new node(13);
    root->right->right      = new node(4);
    root->left->left->left  = new node(7);
    root->left->left->right = new node(2);
    root->right->right->right = new node(1);

    int targetSum = 22;
    if(hasPathSum(root, targetSum))
        cout << "Path exists with sum " << targetSum << endl;
    else
        cout << "No path with sum " << targetSum << endl;

    return 0;
}