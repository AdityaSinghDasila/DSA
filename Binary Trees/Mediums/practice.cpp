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

void preorder(node* root){
    if(root== nullptr)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int findHeight(node* root){
    if(root == nullptr)
        return 0;
    int lt = findHeight(root ->left);
    int rt = findHeight(root->right);
    return 1+max(lt,rt);
}

int findDiameter(node* root, int& ans){
    if(root == nullptr)
        return 0;
    int rt = findDiameter(root->left,ans);
    int lt = findDiameter(root->right,ans);
    ans = max(ans,rt+lt+1);
    return 1+max(rt,lt);
}

int checkBalance(node* root){
    //if therese a height difference greater than 1 at any point, return -1
    if(root==nullptr)
        return 0;
    int lt = checkBalance(root ->left);
    int rt = checkBalance(root ->right);
    if(lt==-1 || rt == -1)
        return -1;
    if(abs(lt-rt)>1)
        return -1;
    return 1 + max(lt,rt);
}

int maxPathSum(node* root,int& ans){
    if(root == nullptr)
        return 0;
    int lt = maxPathSum(root->left,ans);
    int rt = maxPathSum(root->right,ans);
    if(lt<0)
    {
        lt = 0;
    }
    if(rt<0)
    {
        rt=0;
    }
    ans = max(ans,root->val+rt+lt);
    return root->val+max(rt,lt);
}

int main(){
    //making a bt
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);

    root->left->left = new node(-3);
    root->left->right = new node(-1);

    
    root->right->right = new node(4);

    cout<<endl<<"The bt : ";
    preorder(root);
    int dans =0;
    int mpsans = 0;

    int height = findHeight(root);
    int Diameter = findDiameter(root,dans);
    int balance = checkBalance(root);
    int maxSP = maxPathSum(root,mpsans);
    
    cout<<endl<<"The height : "<<height;
    cout<<endl<<"The Diameter : "<<dans;

    if(balance!=-1)
    {
        cout<<endl<<"The BT is balanced!";
    }else{
        cout<<endl<<"The BT is not balanced";
    }

    cout<<endl<<"The maximum Path sum : "<<mpsans;


    return 0;
}