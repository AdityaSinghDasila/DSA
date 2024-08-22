#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = nullptr;
        right = nullptr; 
    }
};
void inOrder(node* root){
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root -> left ->left = new node(100);
    root -> right -> left = new node(99);
    root ->right->right= new node(77);
    
    //now lets apply dfs traversals
    cout<<endl<<"The inorder traversal of the binary tree : ";
    inOrder(root);

    cout<<endl<<"The preorder traversal of the binary tree : ";
    preOrder(root);

    cout<<endl<<"The postorder traversal of the binary tree : ";
    postOrder(root);

    return 0;
}