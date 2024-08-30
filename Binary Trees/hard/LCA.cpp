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

node* lca(node* root,node* p, node* q){
    if(root == nullptr || root == p || root == nullptr)
        return root;
    node* lt = lca(root->left,p,q);
    node* rt = lca(root->right,p,q);
    if(lt == nullptr && rt == nullptr)
    {
        return nullptr;
    }
    else if(lt == nullptr){
        return rt;
    }
    else if(rt == nullptr){
        return lt;
    }
    else{
        return root;
    }
}

int main(){
    //making bt
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    root->right->left = new node(0);
    root->right->right = new node(8);

    preOrder(root);
    node* p = root->left->left;
    node* q = root->right->left;

    node* ans = lca(root,p,q);
    cout<<endl<<"The lowest common ancestor is : "<<ans->val;

    return 0;
}