#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right =nullptr;
    }
};

void inOrder(node* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

node* findMin(node* root,int& mini){

    if(root==nullptr || root->left == nullptr){
        if(root!=nullptr)
            mini = min(mini,root->val); 
        return root;
    }
    return findMin(root->left,mini);
}

node* findMax(node* root, int& maxi){
    if(root == nullptr || root->right == nullptr){
        if(root!=nullptr)   
            maxi = max(maxi,root->val);
        return root;
    }
    return findMax(root->right,maxi);
}

int main(){
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(12);

    root->left->left = new node(4);
    root->left->right = new node(7);

    root->right->left= new node(10);
    root->right->right = new node(14);

    inOrder(root);

    int mini = INT_MAX;
    findMin(root,mini);
    int maxi = INT_MIN; 
    findMax(root,maxi);

    if(mini)
        cout<<endl<<"The minimum of bst : "<<mini;
    else
        cout<<endl<<"invalid bst";
    if(maxi)
        cout<<endl<<"The maximum of the bst : "<<maxi;
    else  
        cout<<endl<<"Invalid BST "<<endl;
    return 0;
}