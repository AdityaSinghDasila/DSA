#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void inOrder(node* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int kthsm(node* root,int k ,int& count){
    if(root == nullptr)
        return -1;
    int lt = kthsm(root->left,k,count);
    count++;
    if(count == k)
    {
        return root->val;
    }
    int rt = kthsm(root->right,k,count);
    if(rt!=-1)
    {
        return rt;
    }else if(lt!=-1){
        return lt;
    }else{
        return -1;
    }
}

int main(){
    //making a bst
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(12);

    root->left->left = new node(4);
    root->left->right = new node(7);

    root->right->left= new node(10);
    root->right->right = new node(14);

    cout<<endl<<"The BST : ";
    inOrder(root);

    int k;
    cout<<endl<<"Enter k : ";
    cin>>k;
    
    int count =0;

    int ans  = kthsm(root,k,count);
   if(ans!=-1){
    cout<<endl<<"The kth smallest element of the BST is : ";
    cout<<ans;
   }else{
    cout<<endl<<"NOT found";
   }

    return 0;
}
