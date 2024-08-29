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
    inOrder(root ->left);
    cout<<root->val<<" ";
    inOrder(root ->right);
}

vector<int> topView(node* root){
    vector<int>ans;
    if(root == nullptr)
        return ans;
    //we just have to traverse once and map vertical lines no with the nodes
    //chosing level order traversal as it it the traversal that will touch on the upper layers first
    queue<pair<node*,int>>q;
    q.push({root,0});
    map<int,int>mike;  //this map will contain the vertical along with the first node it had
    while(!q.empty()){
        pair<node*,int> N = q.front();
        q.pop();
        if(mike.find(N.second)==mike.end()){
            mike[N.second] = N.first->val;
        }
        if(N.first ->left)
            q.push({N.first->left,N.second-1});
        if(N.first->right)
            q.push({N.first->right,N.second+1});
    }
    //now the map contains the top view from left to right 
    for(auto i : mike){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    //creating bt
    node* root = new node(1);

    root ->left = new node(2);
    root ->right = new node(3);
    
    root ->left->left = new node(4);
    root ->left->right = new node(5);
    
    root ->right->left = new node(6);
    root ->right->right = new node(7);

    cout<<endl<<"The binary tree : "; 
    inOrder(root);
    //now for the top view of the bt

    vector<int>ans = topView(root);
    
    cout<<endl<<"The top view of BT : ";
    for(int i: ans){
        cout<<i << " ";    
    }

    return 0;
}