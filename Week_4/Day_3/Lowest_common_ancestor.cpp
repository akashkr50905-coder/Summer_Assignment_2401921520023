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

node* lowestCommonAncestor(node* root, node* p, node* q){
        if(root->val==p->val || root->val==q->val)
        return root->val==p->val ? p :q ;
         if(!(p->val < root->val && q->val < root->val) && !(p->val > root->val && q->val > root->val)){
            return root;
         }
         else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
         }
         else {
            return lowestCommonAncestor(root->right,p,q);
         }

}

int main(){
    node* root = new node(6);
    root->left  = new node(2);
    root->right = new node(8);
    root->left->left   = new node(0);
    root->left->right  = new node(4);
    root->right->left  = new node(7);
    root->right->right = new node(9);
    root->left->right->left  = new node(3);
    root->left->right->right = new node(5);

   node* p = root->left;            
   node* q = root->left->right;        
   node* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}