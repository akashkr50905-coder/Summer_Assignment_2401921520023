#include<iostream>
#include<vector>
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

node* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
    if(preStart > preEnd) return NULL;

    node* root = new node(preorder[preStart]);
    int mid = inStart;
    while(inorder[mid] != root->val) mid++;
    int leftSize = mid - inStart;
    root->left  = helper(preorder,preStart+1,preStart+leftSize,inorder,inStart,mid-1);
    root->right = helper(preorder,preStart+leftSize+1,preEnd,inorder,mid+1,inEnd);

    return root;
}

void inorderTrav(node* root){
    if(root == NULL) return;
    inorderTrav(root->left);
    cout << root->val << " ";
    inorderTrav(root->right);
}

void preorderTrav(node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};
    node* root = helper(preorder, 0, preorder.size()-1,inorder,  0, inorder.size()-1);

    cout << "Inorder:  ";
    inorderTrav(root); 
    cout << endl;

    cout << "Preorder: ";
    preorderTrav(root);  
    cout << endl;

    return 0;
}