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

void inOrder(node* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

node* ins(node* root, int n){
    if(root == nullptr){
        node* temp = new node(n);
        return temp;
    }
    node* mover = root;
    while(mover!=nullptr){
        if(mover->val>n){
            if(mover->left==nullptr){
                node* temp = new node(n);
                mover->left = temp;
                break;
            }
            else
                mover = mover ->left;
        }
        else{
            if(mover->right == nullptr){
                node* temp = new node(n);
                mover ->right = temp;
                break;
            }else{
                mover = mover->right;
            }
        }
    }
    return root;    
}

void rev_inOrder(node* root){
    if(root == nullptr)
        return;
    rev_inOrder(root->right);
    cout<<root->val<<" ";
    rev_inOrder(root->left);
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
    rev_inOrder(root);
    // inOrder(root);

    // int n;
    // cout<<endl<<"Enter a node to insert  :";
    // cin>>n;
    // root = ins(root,n);
    // cout<<endl<<"BST after insertion : ";
    // inOrder(root);
    
    // cout<<endl<<"Enter a node to delete : ";
    // cin>>n;
    // root = delNode(root,n);
    // cout<<endl<<"BST after deletion : ";
    // inOrder(root);


    return 0;
}