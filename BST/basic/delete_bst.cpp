#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val=val1;
        left = right = nullptr;
    }
};

void inOrder(node* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

node* rightestChild(node* root){
    if(root==nullptr || root->right==nullptr){
        return root;
    }
    return rightestChild(root->right);
}

node* helpme(node* root){
    if(root->left==nullptr)
        return root->right;
    else if(root->right == nullptr)
        return root->left;
    node* temp = rightestChild(root->left);
    temp->right = root->right;
    root->right = nullptr;
    return root->left;
}

node* delNode(node* root,int n){
    if(root==nullptr)
        return root;
    if(root->val == n){
        root = helpme(root);
    }
    node* mover = root;
    while(mover!=nullptr)
    {   
       if(mover->val >n){
            if(mover->left!=nullptr && mover->left->val == n){
                mover->left = helpme(mover->left);
                break;
            }
            else{
                mover = mover->left;
            }
       }
       else{
         if(mover->right!=nullptr && mover->right->val == n){
                mover ->right = helpme(mover->right);
                break;
            }
        else{
                mover = mover->right;
            }
       }
    }
    return root;
}

int main(){
    
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(12);

    root->left->left = new node(4);
    root->left->right = new node(7);

    root->right->left= new node(10);
    root->right->right = new node(14);

    cout<<endl<<"The BST : ";
    inOrder(root);

    int n;
    cout<<endl<<"enter the node you want to delete : ";
    cin>>n;

    root = delNode(root,n);

    cout<<endl<<"BST after deletion : ";
    inOrder(root);

    return 0;
}