#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val; 
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right  = nullptr;
    }
};

void inOrder(node* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int checkBalance(node* root){
    //we know how to calculate the height
    //if at any instant the height of lt and rt have a difference of more than 1, then the bt is not balanced
    if(root == nullptr)
        return 0;
    int lt = checkBalance(root->left);
    if(lt==-1)
    {
        return -1;
    }
    int rt = checkBalance(root->right);
    if(rt==-1){
        return -1;
    }
    if(abs(lt-rt)>1){
        return -1;
    }
    return 1 + max(rt,lt);
}

int main(){
    //making a bt
    node* root = new node(1);
    
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(100);
    root->left->left->left->left = new node(200);
    root->left->left->left->left->left = new node(400);


    root->right->left = new node(6);
    root->right->right = new node(7);

    inOrder(root);

    //check if bt is balanced
    int ans = checkBalance(root);
    cout<<endl<<"The ans : "<<ans;
    if(ans!=-1){
        cout<<endl<<"The BT is balanced!";
    }else{
        cout<<endl<<"The BT is NOT balanced!!";
    }
    return 0;
}