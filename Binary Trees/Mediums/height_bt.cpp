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
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(node* root){
    if(root==nullptr)
        return 0;
    int lt = height(root->left);
    int rt = height(root->right);

    return 1 + max(lt,rt);
}

int main(){
    //making a bt
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root ->left ->left = new node(4);
    root ->left ->right = new node(5);
    
    root ->right ->left = new node(6);
    root ->right ->right = new node(7);

    preOrder(root);    

    int ans = height(root);

    cout<<endl<<"The height of the binary tree : "<<ans;

    return 0;
}