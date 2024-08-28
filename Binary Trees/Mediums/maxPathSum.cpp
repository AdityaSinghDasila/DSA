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

int maxPathSum(node* root,int& sum){
    if(root == nullptr)
        return 0;
    int rt = maxPathSum(root->left,sum);
    int lt = maxPathSum(root->right,sum);
    sum = max(sum,rt+lt+root->val);
    return root->val + max(rt,lt);
}

int main(){
    node* root = new node(1);
    
    root->left = new  node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    int sum =0;
    preOrder(root);
    maxPathSum(root,sum);
    cout<<endl<<"The maximum path sum for the BT is  : "<<sum<<endl;
    return 0;
}