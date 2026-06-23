#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val=x;
        left=right=NULL;
    }
};
node* buildTree(vector<int>& tree , int&idx){
     idx++;
    if(tree[idx]==-1){
        return NULL;
    }
    node*root = new node(tree[idx]);
    root->left = buildTree(tree, idx);
    root->right = buildTree(tree, idx);
    return root;
}
void inorderTrav(node* root, vector<int>&ans) {
    if(root==NULL){
        return;
    }
     inorderTrav(root->left,ans);
     ans.push_back(root->val);
     inorderTrav(root->right,ans);
}
int main(){
    vector<int>tree={1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, 8, 9, -1, -1, -1};
    vector<int>ans;
    int idx=-1;
    node* root=buildTree(tree,idx);
    inorderTrav(root,ans);
    for(int val: ans){
        cout<<" "<<val;
    }
    return 0;
}