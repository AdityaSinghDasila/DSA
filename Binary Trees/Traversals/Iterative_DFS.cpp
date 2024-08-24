#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        right = left = nullptr;
    }
};
vector<int> iPreorder(node* root){
    vector<int>ans;
    if(root == nullptr){    
        return ans;
    }
    stack<node*>steve;
    steve.push(root);
    while(!steve.empty()){
        node* N = steve.top();
        steve.pop();
        if(N->right !=nullptr)
            steve.push(N->right);
        if(N->left!=nullptr)
            steve.push(N->left);
        ans.push_back(N->val);
    }
    return ans;
}

vector<int> iInorder(node* root){
    vector<int>ans;
    if(root==nullptr)
        return ans;
    stack<node*>steve;
    node* N = root;
    while(true){
        if(N!=nullptr){
            steve.push(N);
            N = N->left;
        }
        else{
            if(steve.empty()){
                break;
            }
            N = steve.top();
            steve.pop();
            ans.push_back(N->val);
            N = N->right;
        }
    }
    return ans;
}

vector<int> iPostorder(node* root){
    vector<int>ans;
    if(root==nullptr){
        return ans;
    }
    node* N = root;
    stack<node*> steve;
    while(true){
        if(N!=nullptr){
            steve.push(N);
            N = N->left;
        }
        else{
            if(steve.empty())
            {
                break;
            }
            N = steve.top();
            if(N->right==nullptr){
                ans.push_back(N->val);
                steve.pop();
                N = steve.top();
            }else{
                N = N->right;
            }
        }
    }
    return ans;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root -> right = new node(3);

    root -> left ->left = new node(4);
    root -> left -> right = new node(5);
    
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);

    // vector<int>ans = iPreorder(root);
    // vector<int>ans = iInorder(root);
    vector<int>ans = iPostorder(root);

    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}