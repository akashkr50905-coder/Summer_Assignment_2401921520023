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
bool isSame(node* p,node*q){
  if(p==NULL||q==NULL)return p==q;
  bool isLeftSame=isSame(p->left,q->left);
  bool isRightSame=isSame(p->right,q->right);
   return isRightSame && isLeftSame && p->val==q->val;
}
node* buildTree(vector<int>tree, int& idx){  
    idx++;
    if(tree[idx]==-1){
        return NULL;
    }
    node*root = new node(tree[idx]);
    root->left = buildTree(tree, idx);
    root->right = buildTree(tree, idx);
    return root;
}
int main(){
    vector<int>tree1 ={1,2,-1,-1,3,-1,-1};
    vector<int>tree2 ={1,2,-1,-1,3,-1,-1};
    int idx1=-1;
    int idx2=-1;
    node* p= buildTree(tree1,idx1);
    node* q= buildTree(tree2,idx2);
    cout<<isSame(p,q);
    return 0;
}