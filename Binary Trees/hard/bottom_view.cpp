#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val  = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr)
        return;
    cout<<root->val<<" ";
    preOrder(root ->left);
    preOrder(root->right);
}

vector<int> bottom(node* root){
    vector<int> ans;
    if(root == nullptr)
    {
        return ans;
    }
    //the same as top view but, replace with every new occurence untill you reach the last occurence
    queue<pair<node*,int>>q;
    q.push({root,0});
    map<int,int>mike;
    while(!q.empty()){
        pair<node*,int> N = q.front();
        q.pop();
        mike[N.second]=N.first->val;
        if(N.first->left)
            q.push({N.first->left,N.second-1});
        if(N.first->right)
            q.push({N.first->right,N.second+1});
    }//with this, the map has been filled
    for(auto i: mike){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    node* root = new node(1);
    
    root ->left = new node(2);
    root ->right = new node(3);

    root ->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<endl<<"The preorder traversal of bt : "; 
    preOrder(root);
    
    vector<int>ans = bottom(root);
    cout<<endl<<"The bottom view of the BT : ";
    //printing the ans 
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl<<"REached the end!";
    return 0;
} //This is a naive sol..
//Keep the record of level, to compare the nodes at the same level and put the node which is larger.