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
int ans=0;
int height(node* root){
   if(root==NULL)return 0;
   int leftHeight= height(root->left);
   int rightHeight= height(root->right);
   ans= max((leftHeight+rightHeight),ans);
   return max(leftHeight,rightHeight)+1;
}
int diameterOfBinaryTree(node* root){
    ans = 0; 
    height(root);
    return ans;
}
int main(){
    node*root=new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
     cout<<"Diameter of the tree is: "<<diameterOfBinaryTree(root);
}