#include<iostream>
#include<vector>
#include<string>
#include<sstream>
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

// SERIALIZE
void serializeHelper(node* root, string& s){
    if(root == NULL){
        s += "N,";   // N for null
        return;
    }
    s += to_string(root->val) + ",";
    serializeHelper(root->left,  s);
    serializeHelper(root->right, s);
}

string serialize(node* root){
    string s = "";
    serializeHelper(root, s);
    return s;
}
node* deserializeHelper(vector<string>& tokens, int& idx){
    if(tokens[idx] == "N"){
        idx++;
        return NULL;
    }
    node* root = new node(stoi(tokens[idx]));
    idx++;
    root->left  = deserializeHelper(tokens, idx);
    root->right = deserializeHelper(tokens, idx);
    return root;
}

vector<string> split(string& s){
    vector<string> tokens;
    string token = "";
    for(char c : s){
        if(c == ','){
            tokens.push_back(token);
            token = "";
        }
        else{
            token += c;
        }
    }
    return tokens;
}

node* deserialize(string s){
    vector<string> tokens = split(s);
    int idx = 0;
    return deserializeHelper(tokens, idx);
}

void preorder(node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    // build tree [1,2,3,null,null,4,5]
    node* root         = new node(1);
    root->left         = new node(2);
    root->right        = new node(3);
    root->right->left  = new node(4);
    root->right->right = new node(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    node* newRoot = deserialize(serialized);
    cout << "Inorder after deserialize: ";
    preorder(newRoot);
    cout << endl;

    return 0;
}