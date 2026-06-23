#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
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

node* buildTree(vector<int>& tree, int& idx){
    idx++;
    if(tree[idx] == -1) return NULL;
    node* root = new node(tree[idx]);
    root->left = buildTree(tree, idx);
    root->right = buildTree(tree, idx);
    return root;
}

vector<vector<int>> levelOrder(node* root){
    vector<vector<int>> result;
    if(root == NULL) return result;

    queue<node*> q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        int size = q.size();      
        vector<int> level;        

        for(int i = 0; i < size; i++){
            node* curr = q.front();
            q.pop();
            level.push_back(curr->val);           
            if(curr->left)  q.push(curr->left);   
            if(curr->right) q.push(curr->right);  
        }
         if(count % 2 != 0){
                     reverse(level.begin(), level.end());
                  }
        result.push_back(level); 
        count++; 
    }
    return result;
}

int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, 8, 9, -1, -1, -1};
    int idx = -1;
    node* root = buildTree(tree, idx);

    vector<vector<int>> result = levelOrder(root);

    for(int i = 0; i < result.size(); i++){
       
        for(int val : result[i]){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}