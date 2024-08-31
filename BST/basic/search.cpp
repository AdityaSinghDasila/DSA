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

void preOrder(node* root)
{
    if(root==nullptr)
        return;
    cout<<endl<<root->val;
    preOrder(root->left);
    preOrder(root->right);
}

node* searchBST(node* root, int val)
{
    if(root == nullptr || root->val == val)
        return root;
    if(root->val>val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right,val);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left= new node(6);
    root->right->right = new node(7);

    preOrder(root);

    cout<<endl<<"Enter the val you want to search : ";
    int val;
    cin>>val;

    node* ans = searchBST(root,val);
    if(ans!=nullptr)
    cout<<endl<<"found the node : "<<ans->val;
    else    
        cout<<endl<<"The node was not found : ";
    return 0;
}