#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root){
    if(root==nullptr)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

bool checkPath(node* root, vector<int>& ans,int n){
    if(root == nullptr)
        return false;
    ans.push_back(root->val);
    cout<<endl<<"Pushed : "<<root->val;
    if(root->val == n)
        return true;
    bool lt = checkPath(root->left,ans,n);
    bool rt = checkPath(root->right,ans,n);
    if(lt || rt){
        return true;
    }
    ans.pop_back();
    return false;
}

int main(){
    //construct bt
    node* root = new node(1);
    
    root->left = new node(2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<endl<<"The binary tree  : ";
    preOrder(root);

    vector<int>ans;
    cout<<endl<<"Enter the node you want the path to :";
    int n;
    cin>>n;
    bool ret = checkPath(root,ans,n);
    if(ret){
        cout<<endl<<"The path to the node from ROOT : ";
        for(int i : ans){
            cout<<i<<" ";
        }
    }else{
        cout<<"The node was not found!";
    }
    return 0;
}