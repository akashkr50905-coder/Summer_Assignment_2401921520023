#include<iostream>
#include<vector>
using namespace std;
struct node{
 int val;
 node* left;
 node*right;
 node(int x){
    val=x;
    left=right=NULL;
 }
 
};
node* insert(node* root,int val){
   if(root==NULL)return new node(val);
   
   if(val< root->val){
    root->left=insert(root->left, val);
   }
   else if(val> root->val){
    root->right=insert(root->right,val);
   }
   return root;
}
 node* searchBST(node* root, int val) {
      if(root== NULL)return NULL;
       else if(root->val < val){
        return searchBST(root->right,val);
       }
       else if(root->val >val){
        return searchBST(root->left,val);
       }
       else if(root->val==val){
        return root;
       }
       return NULL;
    }
 void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main(){
    vector<int> tree={4,2,7,1,3};
    node* root=NULL;
    for(int v:tree){
        root=insert(root,v);
    }
    int val=2;
   node* newRoot= searchBST(root,val);
   inorder(newRoot);
    return 0;
}