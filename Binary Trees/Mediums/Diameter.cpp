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
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int findDiameter(node* root, int& ans){
    if(root == nullptr){
        return 0;
    }
    int lt = findDiameter(root->left,ans);
    int rt = findDiameter(root->right,ans);
    ans = max(ans,lt+rt);
    return 1 + max(lt,rt);
}

int main(){

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root ->right->left = new node(6);
    root ->right->right = new node(7);

    postOrder(root);
    int ans =0;
    findDiameter(root,ans);
    cout<<endl<<"The diameter of the BT is : "<<ans;

    return 0;
}