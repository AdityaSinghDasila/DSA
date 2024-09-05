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
    if(root == nullptr)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

node* insert(int element, node* root){
    if(root==nullptr){
        node* temp = new node(element);
        cout<<endl<<"Attatched  : "<<temp->val;
        return temp;
    }
    if(root->val > element){
        root->left = insert(element,root->left);
        return root;
    }
    else{
        root->right = insert(element,root->right);
        return root;
    }
}

node* constructBST(vector<int> preorder,int pi,node* root){
    if(pi == preorder.size())
        return root;
    root = insert(preorder[pi],root);
    return constructBST(preorder,pi+1,root);
}

int main(){
    //preorder given.
    vector<int> preorder = {8,5,1,7,10,12};
    cout<<"Given preorder traversal : ";
    for(int i : preorder){
        cout<<i<<" ";
    }
    int pi =0;
    node* root = nullptr;
    root = constructBST(preorder,pi,root);
    
    cout<<endl<<"The constructed BST : ";
    preOrder(root);

    return 0;
}