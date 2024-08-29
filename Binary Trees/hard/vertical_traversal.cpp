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

void verticalOrder(node* root){
     if(root==nullptr)
        return;
    //a queue that will store node*,row and col
    queue<pair<node*,pair<int,int>>> q;
    pair<node*,pair<int,int>>ha;
    ha ={root,{0,0}};
    map<int,map<int,multiset<node*>>>mike;
    q.push(ha);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            ha = q.front();
            q.pop();
            mike[ha.second.second][ha.second.first].insert(ha.first);
            if(ha.first->left!=nullptr)
                q.push({ha.first->left,{ha.second.first+1,ha.second.second-1}});
            if(ha.first->right!=nullptr)
                q.push({ha.first->right,{ha.second.first+1,ha.second.second+1}});
        }
    }
    //now the map mike has the info we need to print
    cout<<endl<<"The vertical order traversal of the the bt is :";
    for(auto i : mike){
        for(auto j : i.second){
            for(auto k : j.second){
                cout<<k->val<<" "; 
            }
        }
    }
}

int main(){
    //making a bt
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left= new node(4);
    root->left->right= new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    //the vertical order traversal of the above bt should be : 4, 2, 1 5 6, 3 ,7
    verticalOrder(root);
    return 0;
}
