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

vector<vector<int>> levelOrder(node* root){
    vector<vector<int>>ans;
    if(root==nullptr)
        return ans;
    queue<node*>qu;
    qu.push(root);
    while(qu.size()!=0){
        int size = qu.size();
        vector<int>temp;
        for(int i = 0;i<size;i++){
            node* N = qu.front();
            qu.pop();
            
            if(N->left!=nullptr)
                qu.push(N->left);
            if(N->right!=nullptr)
                qu.push(N->right);

            temp.push_back(N->val);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    node* root = new node(1);
    root ->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right= new node(7);

    vector<vector<int>>ans = levelOrder(root);
    cout<<endl<<"The level order traversal BFS of the binary tree is : ";
    for(auto i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
    }
    
    return 0;
}