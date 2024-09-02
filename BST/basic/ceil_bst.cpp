#include <iostream>
#include <bits/stdc++.h>
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

void inOrder(node* root){
    if(root==nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
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

    //finding the ceil of the bst
    int ceil =-1;
    int key;
    cout<<endl<<"Enter the value you want to find the ceil for in the bst : ";
    cin>>key;
    node* mover = root;
    while(mover!=nullptr){
        if(mover->val > key){
            ceil = mover->val;
            mover = mover->left;
        }
        else{
            mover = mover->right;
        }
    }
    cout<<"The ceil of the bst is : "<<ceil;

    return 0;
}