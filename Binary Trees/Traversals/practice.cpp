//DFS traversals of a binary tree
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

void inorder(node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == nullptr){
            return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root== nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right= new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    //dfs traversals
    cout<<endl<<"The inorder traversal of the binary tree : ";
    inorder(root);

    cout<<endl<<"The preorder traversal of the binary tree : ";
    preorder(root);

    cout<<endl<<"The postorder traversal of the binary tree : ";
    postorder(root);

    return 0;
}
*/


//BFS traversal of a binary tree
/*
#include <iostream>
#include<bits/stdc++.h>
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
vector<vector<int>> levelOrderTraversal(node* root){
    vector<vector<int>>ans;
    if(root == nullptr){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>temp;
        for(int i = 0;i<size;i++){
            node* N = q.front();
            q.pop();
            if(N->left!=nullptr){
                q.push(N->left);
            }
            if(N->right!=nullptr){
                q.push(N->right);
            }
            temp.push_back(N->val);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    node* root = new node(1);    
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"The level order traversal of the binary tree : ";
    vector<vector<int>>ans = levelOrderTraversal(root);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
    }
    return 0;
}
*/

//iterative DFS 
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;
    node(int val1){
        val=val1;
        left = right = nullptr;
    }
};

vector<int> iPreorder(node* root){
    vector<int>ans;
    if(root==nullptr)
        return ans;
    stack<node*>steve;
    steve.push(root);
    while(!steve.empty())
    {
        node* N = steve.top();
        steve.pop();
        if(N->right!=nullptr)
            steve.push(N->right);
        if(N->left!=nullptr)
            steve.push(N->left);
        ans.push_back(N->val);
    }
    return ans;
}


vector<int> iInorder(node* root){
    vector<int>ans;
    stack<node*>steve;
    node* N = root;
    while(true){
        if(N!=nullptr)
        {
            steve.push(N);
            N = N->left;
        }
        else{
            if(steve.empty()) break;
            N = steve.top();
            ans.push_back(N->val);
            steve.pop();
            N = N->right;
        }
    }
    return ans;
}

vector<int> iPostorder(node* root){  //a self attempt
    
}

int main(){
    node* root = new node(1);
    root ->left = new node(2);
    root -> right = new node(3);

    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);

    // vector<int> ans = iPreorder(root);
    // vector<int> ans = iInorder(root);
    vector<int> ans = iPostorder(root);
    cout<<endl<<"Traversal : ";
    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}
*/

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
vector<int> iPreorder(node* root){
    vector<int>ans;
    stack<node*>steve;
    if(root==nullptr){
        return ans;
    }
    steve.push(root);
    while(!steve.empty()){
        node* N = steve.top();
        steve.pop();
        ans.push_back(N->val);
        if(N->right!=nullptr)
            steve.push(N->right);
        if(N->left !=nullptr)
            steve.push(N->left);
    }
    return ans;
}
vector<int> iInorder(node* root){
    vector<int>ans;
    stack<node*>steve;
    node* N = root;
    while(true){
        if(N!=nullptr){
            steve.push(N);
            N = N->left;
        }
        else{
            if(steve.empty()) break;
            N = steve.top();
            steve.pop();
            ans.push_back(N->val);
            N = N->right;
        }
    }
    return ans;
}
vector<int> iPostorder(node* root){
    
}
int main(){
    node* root = new node(1);
    root ->left = new node(2);
    root ->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    // vector<int> ans = iPreorder(root);
    vector<int> ans = iInorder(root);
    cout<<endl<<"Traversal : ";
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;   
}
*/
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

vector<int> iInorder(node* root){
    vector<int>ans;
    stack<node*>steve;
    node* N = root;
    while(true){
        if(N!=nullptr){
            steve.push(N);
            N = N->left;
        }
        else{
            if(steve.empty()) break;
            N = steve.top();
            steve.pop();
            ans.push_back(N->val);
            N = N->right;
        }
    }
    return ans;
};

vector<int> iPreorder(node* root){
    vector<int> ans;
    stack<node*>steve;
    node* N = root;
    steve.push(root);
    while(!steve.empty()){
        N = steve.top();
        steve.pop();
        ans.push_back(N->val);
        if(N->right!=nullptr)
            steve.push(N->right);
        if(N->left!=nullptr)
            steve.push(N->left);
    }
    return ans;
}

vector<int> iPostorder(node* root){
    //using 2 stacks
    vector<int>ans;
    stack<node*>steve;
    node* N = root;
    steve.push(N);
    while(!steve.empty()){
        N = steve.top();
        steve.pop();
        ans.push_back(N->val);
        if(N->left!=nullptr){
            steve.push(N->left);
        }
        if(N->right!=nullptr){
            steve.push(N->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    //a simple bt
    node* root = new node(1);
    root->left = new node(2);
    root ->right = new node(3);

    root->left->left = new node(4);
    root ->left->right = new node(5);

    root->right ->left= new node(6);
    root->right->right = new node(7);
    // vector<int>ans = iInorder(root);
    // vector<int>ans = iPreorder(root);
    vector<int>ans = iPostorder(root);

    cout<<endl<<"The traversal : ";
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}//I GIVE UP ON iterative POSTORDER traversal through 1 stack
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        right = left = nullptr;
    }
};

vector<vector<int>> allTraversal(node* root){
    vector<vector<int>>ans;
    if(root == nullptr)
        return ans;
    stack<pair<node*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    while(!st.empty()){
        pair<node*,int> N = st.top();
        st.pop();
        
        if(N.second==1){
            pre.push_back(N.first->val);
            N.second++;
            st.push(N);
            if(N.first->left!=nullptr){
                st.push({N.first->left,1});
            }
        }
        else if(N.second == 2){
            in.push_back(N.first->val);
            N.second++;
            st.push(N);
            if(N.first->right!=nullptr){
                st.push({N.first->right,1});
            }
        }
        else if(N.second==3){
            post.push_back(N.first->val);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main(){
    //making a bt
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> ans = allTraversal(root);

    cout<<endl<<"Traversals preorder, inorder and postorder : ";
    for(auto i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}