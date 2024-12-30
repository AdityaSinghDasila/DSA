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
        left = right= nullptr;
    }
};

void preOrder(node* root ){
    if(root == nullptr){
        return;
    }
    cout<<root ->val<<" ";
    preOrder(root ->left);
    preOrder(root ->right);
}

void inOrder(node* root){
    if(root == nullptr){
        return;
    }
    inOrder(root ->left);
    cout<<root->val<<" ";
    inOrder(root ->right);
}

void postOrder(node* root ){
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
    findHeight(root ->right, height, current+1);
}

int findWidth(node* root, int& diameter){
    if(root==nullptr){
        return 0;
    }
    int left = findWidth(root->left,diameter);
    int right = findWidth(root->right,diameter);
    diameter = max(diameter, right+left+1);
    return max(left,right)+1;
}

int findMaxPathSum(node* root, int& sum){
    if(root == nullptr){
        return 0;
    }
    int left = findMaxPathSum(root->left,sum);
    int right = findMaxPathSum(root->right,sum);
    sum = max(sum,left+right+root->val);
    return max(left,right)+root->val;
}

int checkBalance(node* root){
    if(root == nullptr){
        return 0;
    }
    int left = checkBalance(root->left);
    int right = checkBalance(root -> right);
    if(left==-1 || right==-1){
        return -1;
    }
    else if(abs(left-right) >1){
        cout<<endl<<"found the culprit : "<<root->val;
        return -1;
    }
    return max(left,right)+1;
}

int findLca(node* root, int x, int y){
    if(root == nullptr){
        return -1;
    }
    if(root->val == x || root->val ==y){
        return root->val;
    }
    int left = findLca(root->left,x,y);
    int right = findLca(root->right,x,y);

    if(left == -1 && right ==-1)
    {
        return -1;
    }
    if(left!=-1 && right==-1){
        if(root->val == x || root->val ==y){
            return root->val;
        }else{
            return left;
        }
    }else if(left ==-1 && right !=-1){
        if(root->val == x|| root->val ==y){
            return root->val;
        }else{
            return right;
        }
    }else if(left!=-1 && right!=-1){
        return root->val;
    }
    return -1;
}

int findPath(node* root, int n,vector<int>& path){
    if(root==nullptr){
        return -1;
    }
    if(root->val == n){
        path.push_back(root->val);
        return root->val;
    }
    
    int left = findPath(root->left,n,path);
    int right = findPath(root->right,n,path);

    if(left != -1 ){
        path.push_back(root->val);
        return left;
    }else if(right != -1){
        path.push_back(root->val);
        return right;
    }
    return -1;
}

void zigzag(node* root){
    if(root==nullptr){
        return;
    }
    queue<node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        vector<node*> temp;
        int n = q.size();
        for(int i =0;i<n;i++){
            node* m = q.front();
            temp.push_back(m);
            q.pop();
            if(m->left!=nullptr){
                q.push(m->left);
            }
            if(m->right!=nullptr){
                q.push(m->right);
            }
        }
        if(flag){
            for(node* i : temp){
                cout<<i->val<<" ";
                flag = false;
            }
        }else{
            reverse(temp.begin(),temp.end());
            for(node* i : temp){
                cout<<i->val<<" ";
            }
            flag = true;
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

    cout<<endl<<"The level order traversal of the binary tree : ";
    levelOrder(root);

    //find the height of the bt  :
    int height =INT_MIN, current=1;
    findHeight(root,height,current);
    cout<<endl<<"The height of the binary tree : "<<height;

    //find the diameter of the binary tree
    //diameter of the binary tree is the longest path between nodes that may or may not contain the root
    int diameter =0;
    findWidth(root,diameter);
    cout<<endl<<"The diameter of the binary tree is  : "<<diameter;

    //find the max path sum of the binary tree .i.e the path with the maximum sum
    int sum = INT_MIN;
    findMaxPathSum(root,sum);
    cout<<endl<<"The sum form the path with maximum sum is : "<<sum;

    //check if bt is balanced or not i.e the height difference between the left and right subtree is  not more than 1
    int ans = 1;
    ans = checkBalance(root);
    if(ans!=-1){
        cout<<endl<<"The binary tree is balanced ! ";
    }else{
        cout<<endl<<"The binary tree is NOT balanced";
    }

    //find the LCA (lowest common ancestor) of a binary tree
    cout<<"Enter the two nodes for which the LCA is to be found : "<<endl;
    cout<<"x : ";
    int x;
    cin>>x;
    cout<<endl<<"y : ";
    int y;
    cin>>y;
    ans = findLca(root,x,y);
    cout<<endl<<"The lowest common ancestor is  : "<<ans; 

    //find the path from root to a given node
    vector<int> path;
    cout<<endl<<"Enter a node to get a path from root : ";
    int node;
    cin>>node;
    findPath(root,node,path);
    reverse(path.begin(),path.end());
    cout<<endl<<"The path from root to "<<node<<" : ";
    for(int i : path){
        cout<<i<<" ";
    }


    //zig zag traversal of a binary tree
    cout<<endl<<"The zigzag traversal of binary tree : ";
    zigzag(root);

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
    if(root==nullptr){
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
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

void levelOrder(node* root){
    if(root== nullptr){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        cout<<n->val<< " ";
        if(n->left!=nullptr){
            q.push(n->left);
        }
        if(n->right!=nullptr){
            q.push(n->right);
        }
    }
}

void findHeight(node* root, int& height, int current){
    if(root== nullptr){
        return;
    }
    current++;
    height = max(height,current);
    findHeight(root->left,height,current);
    findHeight(root->right,height,current);
}

int findDiameter(node* root, int& diameter){
    if(root==nullptr){
        return 0;
    }
    int left = findDiameter(root->left,diameter);
    int right = findDiameter(root->right,diameter);
    diameter = max(diameter,left+right+1);
    return max(left,right)+1;
}

int checkBalance(node* root){
    if(root == nullptr){
        return 0;
    }
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);
    if(left==-1 || right ==-1){
        return -1;
    }
    if(abs(left-right)>1){
        return -1;
    }
    return max(left,right)+1;
}

int findMaxPathSum(node* root,int& sum){
    if(root == nullptr){
        return 0;
    }
    int left = findMaxPathSum(root->left,sum);
    int right = findMaxPathSum(root->right,sum);
    sum = max(sum,left+right+root->val);
    return max(left,right)+root->val;
}

int checkIdentical(node* root, node* root2){
    if(root==nullptr && root2== nullptr){
        return 1;
    }
    if(root==nullptr){
        cout<<endl<<"Missing node here at : "<<root2->val;
        return -1;
    }
    if(root2==nullptr){
        cout<<endl<<"Missing node here at : "<<root->val;
        return -1;
    }
    if(root->val!=root2->val){
        cout<<endl<<"Different nodes : "<<root->val<<" and "<<root2->val;
        return -1;
    }
    int left = checkIdentical(root->left,root2->left);
    int right = checkIdentical(root->right,root2->right);
    if(left==-1 || right==-1){
        return -1;
    }else{
        return 1;
    }
}

int findLca(node* root,int x, int y){
    if(root==nullptr){
        return -1;
    }
    int left = findLca(root->left,x,y);
    int right = findLca(root->right,x,y);
    if(root->val == x || root->val ==y){
        return root->val;
    }
    if(left == -1){
        return right;
    }else if(right == -1){
        return left;
    }else{
        return root->val;   //left and right both have the x and y. Thus you are currently at the answer
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

    cout<<endl<<"The preOrder traversal of the binary tree :";
    preOrder(root);

    cout<<endl<<"The inOrder traversal of the binary tree : ";
    inOrder(root);

    cout<<endl<<"The postOrder traversal of the binary tree : ";
    postOrder(root);
    
    cout<<endl<<"The level order traversal of the binary tree : ";
    levelOrder(root);

    //find the height of the binary tree:  
    int height =0,current =0;
    findHeight(root,height,current);
    cout<<endl<<"The height of the binary tree is : "<<height;

    //find the diameter of the binary tree 
    int diameter=0;
    findDiameter(root,diameter);
    cout<<endl<<"The diameter of the binary tree: "<<diameter;

    //check if the bt is balanced or not
    int check = 1;
    check = checkBalance(root);
    if(check!=-1){
        cout<<endl<<"The binary tree is BALANCED! ";
    }else{
        cout<<endl<<"The binary tree is NOT balanced!!";
    }

    //find maximum path sum
    int sum = INT_MIN;
    current =0;
    findMaxPathSum(root,sum);
    cout<<endl<<"The maximum path sum is : "<<sum;

    //check if the binary tree is identical or not
    cout<<endl<<endl<<"The first binary tree : ";
    preOrder(root);

    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(11);

    roott->left->left = new node(5);
    roott->left->right = new node(6);

    roott->right->left = new node(0);
    roott->right->right = new node(56);

    roott->left->right->right = new node(3);
    
    roott->left->right->right->right = new node(2);
    roott->left->right->right->right->left = new node(97);
    cout<<endl<<endl<<"The second binary tree : ";
    preOrder(roott); 

    int ans =1;
    ans = checkIdentical(root,roott);
    if(ans!=-1){
        cout<<endl<<"The trees are identical ";
    }else{
        cout<<endl<<"The trees are not identical ";
    }

    //Lowest common ancestor
    ans = INT_MIN;
    int x,y;
    cout<<endl<<"Enter x and y to find their LCA int the binary tree : ";
    cin>>x>>y;
    ans = findLca(root);
    cout<<"The L.C.A : "<<ans;

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
    if(root==nullptr){
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


void zigzag(node* root){
    if(root==nullptr){
        return ;
    }
    queue<node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i =0;i<n;i++){
            node* m = q.front();
            q.pop();
            if(m->left!=nullptr){
                q.push(m->left);
            }
            if(m->right!=nullptr){
                q.push(m->right);
            }
            temp.push_back(m->val);
        }
        if(flag){
            flag = false;
            for(int i : temp){
                cout<<i<<" ";
            }
        }else if(flag == false){
            flag = true;
            reverse(temp.begin(),temp.end());
            for(int i: temp){
                cout<<i<<" ";
            }
        }
    }
}

void findHeight(node* root, int& height, int current){
    if(root == nullptr){
        return;
    }
    current++;
    height = max(height,current);
    findHeight(root->left,height,current);
    findHeight(root->right,height,current);
}

int checkBalance(node* root){
    if(root == nullptr){
        return 0;
    }
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);

    if(left ==-1 || right == -1){
        return -1;
    }
    if(abs(left-right)>1){
        return -1;
    }
    return max(left,right)+1;
}

int findMaxPathSum(node* root, int& sum){
    if(root == nullptr){
        return 0;
    }
    int left = findMaxPathSum(root->left,sum);
    int right = findMaxPathSum(root->right,sum);
    sum = max(sum,left+right+root->val);
    return max(left,right)+root->val;
}

int findDiameter(node* root, int& diameter){
    if(root== nullptr){
        return 0;
    }
    int left = findDiameter(root->left,diameter);
    int right = findDiameter(root->right,diameter);
    diameter = max(diameter,left+right+1);
    return max(left,right)+1;
}

int checkIdentical(node* root1, node* root2){
    if(root1 == nullptr && root2 == nullptr){
        return 0;
    }
    if((root1 == nullptr && root2!=nullptr) || (root1!=nullptr && root2==nullptr)){
        cout<<endl<<"A node is missing at ";
        if(root1==nullptr){
            cout<<root2->val<<" ";
        }else{
            cout<<root1->val<<" ";
        }
        return -1;
    }
    if(root1->val != root2->val){
        cout<<endl<<"Value does not match  : "<<root1->val<<" and "<<root2->val;
        return -1;
    }
    return 1;
}

int getPath(node* root, int x){
    if(root == nullptr){
        return -1;
    }
    int left = getPath(root->left,x);
    int right = getPath(root->right,x);
    if(left == x || right == x){
        cout<<root->val<<" ";
        return x;
    }
    if(root->val == x){
        cout<<root->val<<" ";
        return root->val;
    }else{
        return -1;
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

    cout<<endl<<"The preOrder traversal of the binary tree  : ";
    preOrder(root);

    cout<<endl<<"The inOrder traversal of the binary tree : ";
    inOrder(root);

    cout<<endl<<"The postOrder traversal of the bianry tree : ";
    postOrder(root);

    cout<<endl<<"The levelOrder traversal of the binary tree : ";
    levelOrder(root);

    cout<<endl<<"The zigzag traversal of the binary tree : ";
    zigzag(root);

    //find the height
    int height=INT_MIN,current=0;
    findHeight(root,height,current);
    current =0;
    cout<<endl<<"The height of the binary tree : "<<height;

    //check balance of bt
    int check = 1;
    check = checkBalance(root);
    if(check!=-1){
        cout<<endl<<"The binary tree is BALANCED!!";
    }else{
        cout<<endl<<"The binary tree is NOT balanced";
    }

    //find maxpath sum
    int sum = INT_MIN;
    findMaxPathSum(root,sum);
    cout<<endl<<"The maximum path sum : "<<sum;

    //find the diameter 
    int diameter = INT_MIN;
    findDiameter(root,diameter);
    cout<<endl<<"The diameter of the binary tree : "<<diameter;

    cout<<endl<<"The preOrder traversal of the 1st binary tree : ";
    preOrder(root);

    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(11);

    roott->left->left = new node(5);
    roott->left->right = new node(6);

    roott->right->left = new node(0);
    roott->right->right = new node(56);

    roott->left->right->right = new node(3);
    
    roott->left->right->right->right = new node(2);
    roott->left->right->right->right->left = new node(97);  

    cout<<endl<<"The preOrder traversal of the 2nd binary tree : ";
    preOrder(roott);

    check =1;
    check = checkIdentical(root,roott);
    if(check!=-1){
        cout<<endl<<"The two trees are Identical! ";
    }else{
        cout<<endl<<"The two trees are NOT identical!! ";
    }

    //give the path to node
    int x;
    cout<<endl<<"Enter the node to which you need the path : ";
    cin>>x;
    getPath(root,x);

    return 0;
}
*/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public : 
    int val;
    node* left;
    node* right;
    //constructor
    node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

void preOrder(node* root ){
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
        if(n->left !=nullptr){
            q.push(n->left);
        }
        if(n->right !=nullptr){
            q.push(n->right);
        }
    }
}

void zigZag(node* root){
    if(root == nullptr){
        return;
    }
    bool flag = 1;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i=0;i<n;i++){
            node* m = q.front();
            q.pop();
            if(m->left!=nullptr){
                q.push(m->left);
            }
            if(m->right !=nullptr){
                q.push(m->right);
            }
            temp.push_back(m->val);
        }
        if(flag){
            flag =0;
            for(int i : temp){
                cout<<i<<" ";
            }
        }else{
            flag =1;
            reverse(temp.begin(),temp.end());
            for(int i : temp){
                cout<<i<<" ";
            }
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

    //Tree traversal : 
    cout<<endl<<"The preOrder traversal of the tree : ";
    preOrder(root);

    cout<<endl<<"The inOrder traversal of the tree : ";
    inOrder(root);

    cout<<endl<<"The postOrder traversal of the tree : ";
    postOrder(root);

    cout<<endl<<"The level order traversal of the tree : ";
    levelOrder(root);

    cout<<endl<<"The zigzag traversal of the tree : ";
    zigZag(root);

    return 0;
}