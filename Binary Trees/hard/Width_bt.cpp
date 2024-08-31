#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right=nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr)
        return ;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);    
}

int findWidth(node* root){
    int w = 0;
    if(root==nullptr)
        return 0;
    queue<pair<node*,int>>q;
    q.push({root,0});
    int start,last;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            pair<node*,int> N = q.front();
            if(i==0)
                start = N.second;
            if(i==size-1){
                last = N.second;
                w = max(w,last-start+1);
            }
            q.push({N.first->left,2*N.second+1});
            q.push({N.first->left,2*N.second+2});// I GIVE UP
        }
    }
}

int main(){
    //making a bt :
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
    
    int ans = findWidth(root);

    return 0;
}