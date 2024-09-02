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

    //floor, largest node that is lesser than or equal to key
    node* mover = root;
    cout<<endl<<"Enter the no you want to find the floor for in the bst : ";
    int key;
    int floor=-1;
    cin>>key;
    while(mover!=nullptr){
        if(mover->val == key){
            floor = mover ->val;
            break;
        }
        else if(mover->val >key)
        {
            mover = mover->left;
        }
        else{
            floor=mover ->val;
            mover = mover ->right;
        }
    }
    
    if(floor!=-1)
    cout<<endl<<"The floor of the key in the bst is : "<<floor;
    else    
    cout<<endl<<"No floor for the key in this bst";

    return 0;
}