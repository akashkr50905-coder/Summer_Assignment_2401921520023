#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
node* buildTree(vector<int>tree){
    static int idx=-1;
    idx++;
    if(tree[idx]==-1){
        return NULL;
    }
    node*root = new node(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);
    return root;
}
int maxDepth(node*root){
    if(root==NULL){
        return 0;
    }
    int left_ht= maxDepth(root->left);
    int right_ht= maxDepth(root->right);
    return max(left_ht,right_ht)+1;
}
int main(){
    vector<int>tree={3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    node* root=buildTree(tree);
    cout<<" max depth is: "<<maxDepth(root);
     
    return 0;
}