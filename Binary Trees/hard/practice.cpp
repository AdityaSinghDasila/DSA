//find the LCA of two nodes in the bt
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

void postOrder(node* root){
    if(root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

node* findLca(node* root,node* p, node* q){
    if(root == nullptr || root==p || root == q){
        return root;
    }
    node* lt = findLca(root->left,p,q);
    node* rt = findLca(root->right,p,q);
    if(lt==nullptr && rt==nullptr)
        return nullptr;
    if(lt == nullptr)
        return rt;
    if(rt == nullptr)
        return lt;
    else{
        return root;
    }
}

int main(){
    //making a bt
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    root->right->left = new node(0);
    root->right->right = new node(8);

    postOrder(root);
    node* p = root->left;
    node* q = root->left->right->right;

    //fnc call for LCA function
    node* lca = findLca(root,p,q);

    cout<<endl<<"The LCA for the bt is : "<<lca->val;

    return 0;
}
*/


//bottom view of a bt
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    node(int val1){
        val = val1;
        left=right=nullptr;
    }
};

void preOrder(node* root){
    if(root == nullptr)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<int> topView(node* root){
    vector<int>ans;
    if(root==nullptr)
        return ans;
    map<int,node*> mike;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        pair<node*,int> N = q.front();
        q.pop();
        if(mike.find(N.second)==mike.end()){
            mike[N.second] = N.first;
        }
        if(N.first->left != nullptr)
            q.push({N.first->left,N.second-1});
        if(N.first->right!=nullptr)
            q.push({N.first->right,N.second+1});
    }//now the map contains 
    for(auto i : mike){
        ans.push_back(i.second->val);
    }
    return ans;
}

int main(){ 
    //making the bt
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    root->right->left = new node(0);
    root->right->right = new node(8);
    
    preOrder(root);

    vector<int> top = topView(root);

    cout<<endl<<"The top view of the bt is : ";
    for(int i : top){
        cout<<i<<" ";
    }

    return 0;
}
*/

//practice
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
        left = right = nullptr;
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

int findSymmetry(node* root, node* roott){
    if(root==nullptr && roott == nullptr){
        return 1;
    }
    if((root == nullptr && roott!=nullptr) || (roott == nullptr && root!=nullptr)){
        cout<<endl<<"A whole node is missing!";
        return -1;
    }
    int left = findSymmetry(root->left,roott->left);
    int right = findSymmetry(root->right,roott->right);
    if(left ==-1 || right ==-1){
        return -1;
    }
    if(root->val != roott->val){
        cout<<endl<<"Here we fed up "<<root->val<<" & "<<roott->val;
        return -1;
    }else{
        return 1;
    }
    return 1;
}

int main(){

    //first tree: 
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


    //second tree
    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(11);

    roott->left->left = new node(5);
    roott->left->right = new node(6);

    roott->right->left = new node(23);//here the tree is not the same, it is 0 in the above tree instead of 23
    roott->right->right = new node(56);

    roott->left->right->right = new node(3);
    
    roott->left->right->right->right = new node(2);
    roott->left->right->right->right->left = new node(97);

    //printing both trees :
    cout<<endl<<"The 1st Binary tree preorder traversal : ";
    preOrder(root);
    cout<<endl<<"The 2nd Binary tree preorder traversal : ";
    preOrder(roott);

    int ans =1;
    ans = findSymmetry(root,roott);
    if(ans==-1){
        cout<<endl<<"The two binary trees are NOT symmetrical!!";
    }else{
        cout<<endl<<"The two binary trees are SYMMETRICAL!!";
    }


    return 0;
}
*/

//practice
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
        left = right = nullptr;
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
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root==nullptr){
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

void findHeight(node* root, int& height, int current){
    if(root == nullptr){
        return;
    }
    height = max(height,current);
    findHeight(root->left,height,current+1);
    findHeight(root->right,height,current+1);
}

void findMaxPathSum(node* root,int& maxSum, int current){
    if(root== nullptr){
        return;
    }
    current += root->val;
    maxSum = max(maxSum,current);
    findMaxPathSum(root->left,maxSum,current);
    findMaxPathSum(root->right,maxSum,current);
}

int findDiameter(node* root, int& diameter){
    if(root==nullptr){
        return 0;
    }
    int left = findDiameter(root->left, diameter);
    int right = findDiameter(root->right, diameter);

    diameter = max(diameter, left + right +1);

    return max(left,right)+1;
}

int checkBalance(node* root){
    if(root == nullptr){
        return 0;
    }
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);
    if(left ==-1 || right ==-1){
        return -1;
    }
    if(abs(left-right)>1){
        cout<<endl<<"found you : "<<root->val<<" where left/right: "<<left<<"/"<<right;
        return -1;
    }
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

    cout<<endl<<"The preOrder traversal of the binary tree : ";
    preOrder(root);

    cout<<endl<<"The inOrder traversal of the binary tree : ";
    inOrder(root);

    cout<<endl<<"The postOrder traversal of the binary tree : ";
    postOrder(root);

    cout<<endl<<"The levelOrder traversal of the binary tree : ";
    levelOrder(root);

    //height of bt
    int height=0,current=1;
    findHeight(root,height,current);
    cout<<endl<<"The height of the binary tree is : "<<height;

    //path with max sum, find the sum
    current = 0;
    int maxSum = INT_MIN;
    findMaxPathSum(root,maxSum,current);;
    cout<<"The maximum sum of the path with max sum  : "<<maxSum;

    //diameter of a bt
    int diameter = 0;
    findDiameter(root, diameter);
    cout<<endl<<"The diameter of the binary tree is : "<<diameter;

    //check if bt is balanced or not (the difference should never be more than 1)
    int ansBalance = checkBalance(root);
    if(ansBalance==-1){
        cout<<endl<<"The tree is not balanced!"; 
    }else{
        cout<<endl<<"The tree is Balanced.";
    }

    return 0;
}
*/


//identical or not
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

void checkSymmetry(node* root, node* root2, bool& flag){
    if(root == nullptr && root2 == nullptr){
        return ;
    }
    if((root==nullptr && root2 != nullptr)||(root2==nullptr && root!=nullptr)){
        cout<<endl<<"A node is missing here!";
        flag = false;
        return;
    }
    if(root->val != root2 ->val){
        cout<<endl<<"The values are different here : "<<root->val<<" and "<<root2->val;
        flag = false;
        return;
    }
    checkSymmetry(root->left,root2->left,flag);
    checkSymmetry(root->right,root2->right,flag);
}

int main(){

    //first tree : 
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

    //second tree :
    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(11);

    roott->left->left = new node(5);
    roott->left->right = new node(6);

    roott->right->left = new node(456); //instead here lies 0 in the first tree
    roott->right->right = new node(56);

    roott->left->right->right = new node(3);
    
    roott->left->right->right->right = new node(2);
    roott->left->right->right->right->left = new node(97);

    cout<<endl<<"The preOrder traversals of the first Btree : ";
    preOrder(root);

    cout<<endl<<"The preOrder traversal of the second Btree : ";
    preOrder(roott);

    bool flag = true;
    checkSymmetry(root,roott,flag);
    if(flag == true){
        cout<<endl<<"The two Binary trees are symmetrical ";
    }else{
        cout<<endl<<"The two Binary trees are NOT SYMMETRICAL ! ";
    }

    return 0;
}
*/

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
        left = right = nullptr;
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
    if(root==nullptr){
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

vector<int> zigzag(node* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    bool lr = true;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i =0;i<n;i++){
            node* m = q.front();
            q.pop();
            temp.push_back(m->val);
            if(m->left!=nullptr){
                q.push(m->left);
            }
            if(m->right!=nullptr){
                q.push(m->right);
            }
        }
        if(lr){
            for(int i =0;i<temp.size();i++){
                ans.push_back(temp[i]);
            }
            lr = false;
        }else{
            reverse(temp.begin(),temp.end());
            for(int i =0;i<temp.size();i++){
                ans.push_back(temp[i]);
            }
            lr = true;
        }
    }
    return ans;
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

    cout<<endl<<"The preOrder, inOrder, postOrder and levelOrder traversal of the BT is : "<<endl;
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);

    //zigzag traversal
    cout<<endl<<"The zigzag traversal of the bt : ";
    vector<int> ans = zigzag(root);
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
class node{
    public :
    int val;
    node* left;
    node* right;
    node(int val1){
        val = val1;
        left = right = nullptr;
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
    if(root == nullptr){
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
    postOrder(root ->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int findDiameter(node* root, int& diameter){
    if(root == nullptr){
        return 0;
    }
    int left = findDiameter(root->left,diameter);
    int right = findDiameter(root ->right, diameter);
    diameter = max(diameter,left+right+1);
    return  max(left,right)+1;
}

void findHeight(node* root, int current, int& height){
    if(root == nullptr){
        return;
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

    //find the diameter of the bt
    int diameter = 0;
    findDiameter(root,diameter);
    cout<<endl<<"The diameter of the binary tree : "<<diameter;

    int current =1,height=INT_MIN;
    findHeight(root,current,height);
    cout<<endl<<"The height of the binary tree : "<<height;

    

    return 0;
}

*/