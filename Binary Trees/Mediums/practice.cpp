/*
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
*/

//revising binary tree traversals


//find the height of the binary tree
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left=right = nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void findHeight(node* root,int& height, int current){
    if(root == nullptr){
        return;
    }
    height = max(height,current);
    findHeight(root->left,height,current+1);
    findHeight(root->right,height,current+1);
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(11);

    root->left->left = new node(5);
    root->left->right = new node(6);

    root->right->left = new node(0);
    root->right->right = new node(56);

    root->left->right->right = new node(3);
    
    root->left->right->right->right = new node(2);
    root->left->right->right->right->left = new node(97);


    cout<<endl<<"The preorder traversal of the binary tree : ";
    preOrder(root);
    
    int height =0;
    findHeight(root,height,1);

    cout<<endl<<"The height of the binary tree : "<<height;    

    return 0;
}
*/

//traversal practice
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    //constructor
    node(int val1){
        val = val1;
        left = right= nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root== nullptr){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}


void levelOrder(node* root){
    if(root == nullptr){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        cout<<n->val<<" ";
        if(n->left!=nullptr){
            q.push(n->left);
        }
        if(n->right!=nullptr){
            q.push(n->right);
        }
    }
}

void findHeight(node* root, int& height, int count){
    if(root==nullptr){
        return;
    }
    height = max(height,count);
    findHeight(root->left,height,count+1);
    findHeight(root->right,height,count+1);
}

void findMaxSumPath(node* root,int sum, int& maxSum){
    if(root==nullptr){
        return;
    }
    sum = sum + root->val;
    maxSum = max(maxSum,sum);
    findMaxSumPath(root->left,sum,maxSum);
    findMaxSumPath(root->right,sum,maxSum);
}

int checkBalance(node* root){
    if(root==nullptr){
        return 0;
    }
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);
    if(left==-1 || right == -1){
        return -1;
    }
    if(abs(left-right)>1){
        cout<<"at this point left and right : "<<left<<" "<<right;
        cout<<" node : "<<root->val<<" ";
        return -1;
    }
    else{
        return max(left,right)+1;
    }
}

int findDiameter(node* root,int& ans){
    if(root==nullptr){
        return 0;
    }
    int left = findDiameter(root->left,ans);
    int right = findDiameter(root->right,ans);
    ans = max(ans,left+right+1);
    return max(left,right)+1;

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(11);

    root->left->left = new node(5);
    root->left->right = new node(6);

    root->right->left = new node(0);
    root->right->right = new node(56);

    root->left->right->right = new node(3);
    
    root->left->right->right->right = new node(2);
    root->left->right->right->right->left = new node(97);

    cout<<endl<<"The preorder traversal of the binary tree : ";
    preOrder(root);
    cout<<endl<<"The inorder traversal of the binary tree : ";
    inOrder(root);
    cout<<endl<<"The postorder traversal of the binary tree : ";
    postOrder(root);

    cout<<endl<<"The level order traversal of the binary tree : ";
    levelOrder(root);

    int height = 0;
    int count =1;
    findHeight(root,height,count);
    cout<<endl<<"The height of the binary tree : "<<height;

    int sum=0;
    int maxSum=0;
    findMaxSumPath(root,sum,maxSum);
    cout<<endl<<"The maximum sum from any path in the binary tree : "<<maxSum;

    int ans = checkBalance(root);
    if(ans!=-1){
        cout<<endl<<"The binary tree was balanced! ";
    }else if(ans==0){
        cout<<endl<<"The BINARY TREE DOES NOT EXIST ";
    }else{
        cout<<endl<<"The binary tree is NOT balanced! "; 
    }

    int diameter=0;
    findDiameter(root,diameter);
    cout<<endl<<"The diameter of the binary tree is : "<<diameter;
     
    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root== nullptr){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root== nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

void levelOrder(node* root){
    if(root==nullptr){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        cout<<n->val<<" ";
        if(n->left!=nullptr){
            q.push(n->left);
        }
        if(n->right!=nullptr){
            q.push(n->right);
        }
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(11);

    root->left->left = new node(5);
    root->left->right = new node(6);

    root->right->left = new node(0);
    root->right->right = new node(56);

    root->left->right->right = new node(3);
    
    root->left->right->right->right = new node(2);
    root->left->right->right->right->left = new node(97);

    cout<<endl<<"The preOrder traversal of the binary tree : ";
    preOrder(root);

    cout<<endl<<"The inOrder traversal of the binary tree : ";
    inOrder(root);

    cout<<endl<<"The postOrder traversal of the binary tree : ";
    postOrder(root);

    cout<<endl<<"The level order traversal of the binary tree: ";
    levelOrder(root);

    return 0;
}