//DFS traversals of a binary tree
/*
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

void inorder(node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == nullptr){
            return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root== nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right= new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    //dfs traversals
    cout<<endl<<"The inorder traversal of the binary tree : ";
    inorder(root);

    cout<<endl<<"The preorder traversal of the binary tree : ";
    preorder(root);

    cout<<endl<<"The postorder traversal of the binary tree : ";
    postorder(root);

    return 0;
}
*/


//BFS traversal of a binary tree
/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right= nullptr;
    }
};
vector<vector<int>> levelOrderTraversal(node* root){
    vector<vector<int>>ans;
    if(root == nullptr){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>temp;
        for(int i = 0;i<size;i++){
            node* N = q.front();
            q.pop();
            if(N->left!=nullptr){
                q.push(N->left);
            }
            if(N->right!=nullptr){
                q.push(N->right);
            }
            temp.push_back(N->val);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    node* root = new node(1);    
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"The level order traversal of the binary tree : ";
    vector<vector<int>>ans = levelOrderTraversal(root);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
    }
    return 0;
}
*/