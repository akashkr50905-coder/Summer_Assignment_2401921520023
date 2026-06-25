#include<iostream>
#include<climits>
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

int ans = INT_MIN; 

int height(node* root){
    if(root == NULL) return 0;
    int leftHt  = max(height(root->left),  0);
    int rightHt = max(height(root->right), 0);
    ans = max(ans, leftHt + rightHt + root->val);
    return max(leftHt, rightHt) + root->val;
}
int maxPathSum(node* root){
    ans = INT_MIN; 
    height(root);
    return ans;
}

int main(){
    // tree: [-10, 9, 20, null, null, 15, 7]
    node* root       = new node(-10);
    root->left       = new node(9);
    root->right      = new node(20);
    root->right->left  = new node(15);
    root->right->right = new node(7);
    cout << "Max Path Sum: " << maxPathSum(root) << endl;
    return 0;
}