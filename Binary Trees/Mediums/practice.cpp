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

void preorder(node* root){
    if(root== nullptr)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int findHeight(node* root){
    if(root == nullptr)
        return 0;
    int lt = findHeight(root ->left);
    int rt = findHeight(root->right);
    return 1+max(lt,rt);
}

int findDiameter(node* root){
    
}

int checkBalance(node* root){

}

int maxPathSum(node* root){

}

int main(){
    //making a bt
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<endl<<"The bt : ";
    preorder(root);

    int height = findHeight(root);
    int Diameter = findDiameter(root);
    int balance = checkBalance(root);
    int maxSP = maxPathSum(root);

    return 0;
}