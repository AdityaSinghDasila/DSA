#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    node(int val1){
        val = val1;
    }
};
void postOrder(node* root){
    if(root==nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

node* constructBT(vector<int> inorder, vector<int> preorder){
    
}

int main(){
    vector<int> inorder ={40,20,50,10,60,30};
    vector<int> preorder = {10,20,40,50,30,60};
    
    cout<<endl<<"The inorder traversal : ";
    for(int i : inorder){
        cout<<i<<" ";
    }    
    cout<<endl<<"The preorder traversal : ";
    for(int i : preorder){
        cout<<i<<" ";
    }

    //constructing a unique bt from these traversal
    node* root = nullptr;
    root = constructBT(inorder,preorder);
    cout<<endl<<"The binary tree in post order traversal : ";
    postOrder(root);

    return 0;
}