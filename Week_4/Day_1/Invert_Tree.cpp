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
   node* invertTree(node* root) {
        if(root==NULL)return NULL ;
        node* temp=root->left;
        root->left= root->right;
        root->right= temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

void preorderTrav(node*root){
    if(root == NULL){
        return ;
    }
       cout<< root->val <<" ";
       preorderTrav(root->left);
       preorderTrav(root->right);
       
}
int main(){
    vector<int>tree={ 4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1};
    node*root=buildTree(tree);
    node* newroot=invertTree(root);
    preorderTrav(newroot);
    return 0;
}