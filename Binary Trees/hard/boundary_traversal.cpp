#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public :
    int val;
    node* left;
    node* right;
    //constructor
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void addLeftBoundary(node* root, vector<int>& ans){
    if(root==nullptr){
        return;
    }
    if(root->left!=nullptr || root->right!=nullptr){
        //this node is exactly what ur looking for rn
        ans.push_back(root->val);
    }
    addLeftBoundary(root->left,ans);
    addLeftBoundary(root->right,ans);
}

void addLeaves(node* root, vector<int>& ans){
    if(root==nullptr){
        return;
    }
    if(root->left == nullptr && root->right==nullptr){
        ans.push_back(root->val);
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans);
}

void addRightBoundary(node* root, vector<int>& ans){
    if(root == nullptr){
        return;
    }
    if(root->left!=nullptr || root->right!=nullptr){
        ans.push_back(root->val);
    }
    addRightBoundary(root->right,ans);
    addRightBoundary(root->left,ans);
}

void boundaryTraversal(node* root){
    if(root==nullptr){
        return;
    }
    vector<int> ans;
    vector<int> rigg;
    ans.push_back(root->val);
    addLeftBoundary(root->left,ans);
    addLeaves(root,ans);
    addRightBoundary(root->right,rigg);

    reverse(rigg.begin(),rigg.end());
    ans.insert(ans.end(),rigg.begin(),rigg.end());
    //now the ans contains the traversal
    for(int i : ans){
        cout<<i<<" ";
    }
}

int main(){

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(8);

    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(5);
    root->left->right->left->left = new node(6);
    root->left->right->left->right = new node(7);

    root->right->left = new node(9);
    root->right->left->left = new node(99);
    root->right->left->right = new node(10);
    root->right->left->right->left = new node(11);
    root->right->left->right->right = new node(12);

    cout<<endl<<"The preOrder traversal of the binary tree :";
    preOrder(root);

    cout<<endl<<"The boundary traversal of the binary tree : ";
    boundaryTraversal(root);

    return 0;

}