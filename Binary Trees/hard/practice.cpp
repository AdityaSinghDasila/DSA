//find the LCA of two nodes in the bt
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

void postOrder(node* root){
    if(root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

node* findLca(node* root,node* p, node* q){
    if(root == nullptr || root==p || root == q){
        return root;
    }
    node* lt = findLca(root->left,p,q);
    node* rt = findLca(root->right,p,q);
    if(lt==nullptr && rt==nullptr)
        return nullptr;
    if(lt == nullptr)
        return rt;
    if(rt == nullptr)
        return lt;
    else{
        return root;
    }
}

int main(){
    //making a bt
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    root->right->left = new node(0);
    root->right->right = new node(8);

    postOrder(root);
    node* p = root->left;
    node* q = root->left->right->right;

    //fnc call for LCA function
    node* lca = findLca(root,p,q);

    cout<<endl<<"The LCA for the bt is : "<<lca->val;

    return 0;
}