#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public :
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int checkIdentical(node* root, node* root2){
    if(root==nullptr && root2== nullptr){
        return 0;
    }
    if(root==nullptr || root2==nullptr){
        cout<<endl<<"A node is missing here : ";
        if(root==nullptr){
            cout<<root2->val<<" ";
        }else{
            cout<<root->val<<" ";
        }
        return -1;
    }
    if(root->val != root2->val){
        cout<<endl<<"different values : "<<root->val<<" "<<root2->val;
        return -1;
    }
    int left = checkIdentical(root->left,root2->left);
    int right = checkIdentical(root->right,root2->right);
    if(left==-1 || right ==-1){
        return -1;
    }
    return 1;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(11);

    root->left->left = new node(5);
    root->left->right = new node(6);

    root->right->left = new node(0);
    root->right->right = new node(56);

    root->left->right->right = new node(3);
    
    root->left->right->right->right = new node(2);
    root->left->right->right->right->left = new node(97);
    
    cout<<endl<<"The preOrder traversal of the first binary tree: ";
    preOrder(root);


    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(11);

    roott->left->left = new node(5);
    roott->left->right = new node(6);

    // roott->right->left = new node(0);
    roott->right->right = new node(56);

    roott->left->right->right = new node(3);
    
    roott->left->right->right->right = new node(2);
    roott->left->right->right->right->left = new node(97);
    
    cout<<endl<<"The preOrder traversal of the second binary tree : ";
    preOrder(roott);

    int ans = 0;
    ans = checkIdentical(root,roott);
    if(ans!=-1){
        cout<<endl<<"The two trees were identical";
    }else{
        cout<<endl<<"The two trees are NOT IDENTICAL!!";
    }

    return 0;
}