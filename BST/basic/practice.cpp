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

node* rightestNode(node* root){
    if(root==nullptr || root->right == nullptr)
        return root;
    return rightestNode(root->right);
}

node* helpme(node* keyNode){
    if(keyNode->left == nullptr){
        return keyNode->right;
    }
    if(keyNode->right == nullptr){
        return keyNode->left;
    }
    node* temp = rightestNode(keyNode->left);
    temp->right = keyNode->right;
    keyNode->right = nullptr;
    return keyNode->left;
}

node* delNode(node* root, int n){
    node* mover = root;
    if(root->val == n){
        root = helpme(root);
        return root;
    }
    while(mover!=nullptr){
        if(mover->val > n){
            if(mover->left!=nullptr && mover->left->val==n){
                mover ->left = helpme(mover->left);
                break;
            }
            else{
                mover = mover->left;
            }
        }
        else{
            if(mover->right!=nullptr && mover->right->val){
                mover->right = helpme(mover->right);
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
    //making a bst
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(12);

    root->left->left = new node(4);
    root->left->right = new node(7);

    root->right->left= new node(10);
    root->right->right = new node(14);

    cout<<endl<<"The bst : ";
    inOrder(root);

    cout<<endl<<"Enter the node you want to delete : ";
    int n;
    cin>>n;
    root = delNode(root,n);

    cout<<endl<<"The BST after deletion : ";
    inOrder(root);

    return 0;
}