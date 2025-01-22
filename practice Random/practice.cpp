//Merge sort: 1. arrays
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int first, int middle, int last){
    //keeping starting pointer for both the sorted virtual arrays
    int i=first;
    int j=middle+1;
    vector<int> temp;
    while(i<=middle && j<=last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //measures to ensure both the virtual arrays have been cooked
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now that both have been cooked and placed inside temp, transfer temp to arr
    for(int i = first;i<=last;i++){
        arr[i]= temp[i-first];
    }
}

void mergeSort(vector<int>& arr,int first, int last){
    if(first>=last)
        return;
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){
    vector<int> arr ={9,2,45,2,1,67,87,45,32,12,5,1,0,4,33,45,6,7,89,9,3,5,4};
    cout<<endl<<";
    int n = maxSumSubArray(arr);The arrays before sorting : ";
    for(int     i: arr){
        cout<<i<<" ";
    } 
    
    cout<<endl<<n<<"";mergeSor is the maximum sum a subarray can have from this arrayt(  
    r,0,arr.size()-1);
    
    cout<<endl<<"The array after sorting : ";
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;
}
*/

// merge sort : 2. Linked list
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
    int data;
    node* next;
    // constructor
    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* findMiddle(node* head){
    if(head==nullptr || head->next==nullptr)
        return head;
    node* f = head->next->next;
    node* s = head;
    while(f!=nullptr && f->next!=nullptr){
        f=f->next->next;
        s=s->next;
    }
    return s;
}

node* mergeLL(node* h1, node* h2){
    node* dummy = new node(-1);
    node* mover = dummy;
    
    node* temp1 = h1;
    node* temp2 = h2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<=temp2->data){
            mover->next = temp1;
            mover = temp1;
            temp1=temp1->next;
        }else{
            mover->next = temp2;
            mover = temp2;
            temp2 = temp2->next;
        }
    }
    //now we make sure both are cooked;
    while(temp1!=nullptr){
        mover->next=temp1;
        mover = temp1;
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        mover ->next = temp2;
        mover = temp2;
        temp2= temp2->next;
    }
    dummy=dummy->next;
    return dummy;
}

node* sortLL(node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* leftHead = head;
    node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    head = mergeLL(leftHead,rightHead);
    return head;
}

int main(){ 

    node* head = new node(-1);
    node* mover = head;
    cout<<"Enter the nodes, enter 100 to stop : ";
    int n;
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover->next = temp;
            mover = temp;
        }
    }while(n!=100);
    head = head->next;
    //lets print the linked list before sorting
    mover = head;
    cout<<endl<<"The linked list : ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }

    head = sortLL(head);

    //lets print what we've cooked
    mover = head;
    cout<<endl<<"The sorted linked list : ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover= mover->next;
    }

    return 0;
}
*/

//*************************arrays practice

//kadanes algorithm
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSumSub(vector<int> arr){
    //now we apply kadanes algorithm
    int MaxSum = INT_MIN;
    int sum =0;
    int start=-1,s=-1,end=-1;
    for(int i=0;i<arr.size();i++){
        if(sum == 0){
            s=i;
        }
        sum +=arr[i];
        if(sum>MaxSum){
            MaxSum = sum;
            start = s;
            end = i;
        }
        if(sum<0){
            sum=0;
        }
    }
    vector<int> ans ={MaxSum,start,end};
    return ans;
}
int main(){

    vector<int>arr ={2,-3,5,-1,2,54,-76,2,12,3,56,8,-9,6,4,-1,0};
    cout<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    vector<int> ans = maxSumSub(arr);
    //first index contains the maximum sum, the other two index contain start and end of that subarray
    cout<<endl<<"The maximum sum is : "<<ans[0];
    cout<<endl<<"The subarray responsible : ";
    for(int i =ans[1];i<=ans[2];i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/

//count subarrays whose sum is equal to k
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSub(vector<int> arr, int k){
    int preSum=0;    
    int count=0;     
    unordered_map<int,int>mike;
    for(int i=0;i<arr.size();i++){
        preSum+=arr[i];
        if(mike.find(preSum-k)!=mike.end()){
            count+=mike[preSum-k];  
        }
                   
        mike[preSum]++;
    }
}

int main(){
    vector<int> arr ={1,2,3,1,1,1,1,3,3};
    int k=6;
    cout<<endl<<"The array : ";
    for(int i: arr){
        cout<<i<<" ";
    }

    int ans = countSub(arr,k);
    cout<<endl<<"The number of subarrays whose sum is "<<k<<" are : "<<ans;

    return 0;
}*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int first, int middle, int last){
    int i = first;
    int j = middle+1;
    vector<int>temp;
    while(i<=middle && j<=last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //now push the leftovers
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }  
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now temp to arr array
    for(int i = 0;i<temp.size();i++){
        arr[first + i] = temp[i];
    }
}
void mergeSort(vector<int>& arr, int first, int last){
    if(first==last){
        return;
    }
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){

    vector<int> arr = {23,4,6,90,12,3,6,2,0,26,8,18,21,1,34,66};
    cout<<endl<<"The array before sorting : ";
    
    for(int i : arr){
        cout<<i<<" ";
    }
    
    cout<<endl<<"The array after sorting : ";

    mergeSort(arr,0,arr.size()-1);

    for(int i : arr){
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
    public:
    int val;
    node* next;
    node(int val1){
        val = val1;
        next = nullptr;
    }
};

node* findMiddle(node* head){
    if(head==nullptr || head->next == nullptr || head->next->next == nullptr){
        return head;
    }
    node* s = head;
    node* f = head->next->next;
    while(f!=nullptr && f->next!=nullptr){
        f = f->next->next;
        s = s->next;
    }
    return s;
}

node* merge2LL(node* h1, node* h2){
    node* dummy = new node(-1);
    node* mover = dummy;
    node* mover1 = h1;
    node* mover2 = h2;
    while(mover1!=nullptr && mover2!=nullptr){
        if(mover1->val <= mover2->val){
            mover->next = mover1;
            mover1 = mover1->next;
            mover = mover->next;
        }else{
            mover->next = mover2;
            mover2 = mover2->next;
            mover = mover->next;
        }
    }
    //make sure to exhaust both 
    while(mover1!=nullptr){
        mover ->next = mover1;
        mover1 = mover1->next;
        mover = mover->next;
    }
    while(mover2!=nullptr){
        mover ->next = mover2;
        mover2 = mover2->next;
        mover = mover->next;
    }
    dummy = dummy->next;
    return dummy;
}


node* mergeSortLL(node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle ->next;
    middle ->next = nullptr;
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    return merge2LL(left,right);
}

int main(){
    node* head = new node(-1);
    node* mover = head;
    int n =-1;
    
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover -> next = temp;
            mover = mover->next;
        }
    }while(n!=100);
    
    head = head->next;

    cout<<endl<<"The formed linked list is : ";
    mover = head;
    while(mover != nullptr){
        cout<<mover->val<<" ->";
        mover = mover->next;
    }
    cout<<"nullptr";

    //sort the linked list by merge sort
    head = mergeSortLL(head);

    cout<<endl<<"The linked list after sorting is : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ->";
        mover = mover ->next;
    }
    cout<<"X";

    return 0;
}
*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumSub(vector<int> arr){
    vector<int> ans;
    int sum =INT_MIN;
    int current =0;
    int n = arr.size();
    int start=0,end=0;
    for(int i = 0;i<n;i++){
        if(current ==  0){
            start = i;
        }
        current += arr[i];
        if(current > sum){
            sum = max(sum,current);
            end = i;
        }
        if(current <0){
            current =0;
        }
    }
    ans.push_back(sum);
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

int main(){
    //kadanes algo is used to find the sub array with the maximum sum. also, this array may contain negative numbers
    vector<int> arr = {3,5,1,6,-13,2,5,1,6,-1,4,-23,5,18,23,-13};
    
    cout<<endl<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    //function call
    vector<int> ans = maxSumSub(arr);

    cout<<endl<<"The maximum sum is : "<<ans[0]<<" from the subarray : [ ";
    for(int i = ans[1];i<=ans[2];i++){
        cout<<arr[i]<<" ";
    }
    cout<<" ]";
    
    return 0;
}
*/




//merge sort
//1.on array
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int first,int middle, int last){
    vector<int> temp;
    int i =first;
    int j = middle+1;
    while(i<=middle && j<=last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //now the left overs that (but those are also sorted)
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now both the imaginary arrays have been exhausted and the temp vector has the sorted combination
    for(int i=first; i<=last;i++){
        arr[i] = temp[i-first];
    }
}

void mergeSort(vector<int>& arr, int first, int last){
    if(first == last)
        return;
    int middle  = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){
    vector<int> arr={84,23,54,2,56,2,1,6,3,8,47,63,23,5,7,9,0,3,4,4,78};
    cout<<endl<<"The array before sorting : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    //applying merge sort
    mergeSort(arr,0,arr.size()-1);

    cout<<endl<<"After sorting, the array becomes : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}
*/

//2.on linked list
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    //constructor
    node(int val1){
        val =val1;
        next = nullptr;
    }  
};

node* mergeSortedLL(node* h1, node* h2){
    node* dummy = new node(-1);
    node* mover = dummy;

    node* temp1 = h1;
    node* temp2 = h2;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->val<=temp2->val){
            mover ->next = temp1;
            temp1=temp1->next;
            mover = mover->next;
        }else{
            mover->next = temp2;
            temp2 = temp2->next;
            mover = mover->next;
        }
    }
    //now to completely exhaust both ll
    while(temp1!=nullptr){
        mover->next = temp1;
        temp1 = temp1->next;
        mover = mover->next;
    }
    while(temp2!=nullptr){
        mover->next = temp2;
        temp2 = temp2->next;
        mover = mover->next;
    }
    dummy = dummy->next;
    return dummy;
}   

node* findMiddle(node* head){
    node* s = head;
    node* f = head->next->next;
    while(f!=nullptr && f->next != nullptr){
        s = s->next;
        f = f->next->next;
    }
    return s;
}

node* mergeSortLL(node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle ->next = nullptr;
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    head = mergeSortedLL(left,right);
    return head;
}

int main(){
    node* head = new node(-1);
    node* mover = head;
    int n=0;
    cout<<endl<<"Enter nodes of the linked list : ";
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover ->next = temp;
            mover = mover->next;
        }
    }while(n!=100);

    head = head->next;
    cout<<"The linked list made : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover->next;
    }

    //call the merge sort on the linked list 
    head = mergeSortLL(head);

    cout<<endl<<"The linked list after the sorting : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover=mover->next;
    }

    return 0;
}
*/


//GRAPHS
//bfs
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> adj, int x){
    vector<int> visited(adj.size(),0);
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        for(int i : adj[n]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs_traversal(vector<vector<int>> adj, vector<int>& visited, int x){
    visited[x]=1;
    cout<<x<<" ";
    for(int i : adj[x]){
        if(visited[i]!=1){
            dfs_traversal(adj,visited,i);
        }
    }
}

int main(){
    cout<<"Enter the nodes and edges : ";
    int n,m;
    cin>>n>>m;
    cout<<endl<<"Enter the edges : ";
    vector<vector<int>> adj(n+1,vector<int>(0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been made

    cout<<endl<<"The adjacency list : "<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }    
    cout<<endl<<"Enter the starting node to traverse from : ";
    int x;
    cin>>x;

    bfs_traversal(adj,x);
    
    vector<int> visited(n+1,0);
    
    cout<<endl<<"DFS : ";
    dfs_traversal(adj,visited,x);

    return 0;
}
*/



//merge sort 
//1. array 
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int first,int middle, int last){
    vector<int> temp;
    int i=first,j=middle+1;
    while(i<=middle && j<=last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{  
            temp.push_back(arr[j]);
            j++;
        }
    }
    //now that one of them is exhausted, time for the other one to fill in
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now temp has the sorted array that is supposed to be in arr from first index to last index
    //time to fill
    for(int i = first;i<=last;i++){
        arr[i]=temp[i-first];
    }
}

void mergeSort(vector<int>& arr, int first, int last){
    if(first>=last){
        return;
    }
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){

    vector<int> arr ={56,34,23,75,1,56,2,7,4,3,8,4,2,0,7,32,4,234,5,89,79};

    cout<<endl<<"The vector before sorting : ";
    for(int i:arr){
        cout<<i<<" "; 
    }

    cout<<endl<<"The vector after sorting : ";
    mergeSort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;
}
*/


//2.linked list
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public :
    int val;
    node* next;
    //constructor
    node(int val1){
        val = val1;
        next = nullptr;
    }
};

node* mergeSortedLL(node* h1, node* h2){
    node* dummy = new node(-1);
    node* mover = dummy;

    node* temp1 = h1;
    node* temp2 = h2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->val <= temp2->val){
            mover->next = temp1;
            temp1 = temp1->next;
            mover = mover->next;
        }else{
            mover ->next = temp2;
            temp2=temp2->next;
            mover = mover->next;
        }
    }
    //now one of the temp has been exhausted, time for the other temp to fill in:
    while(temp1!=nullptr){
        mover->next = temp1;
        temp1= temp1->next;
        mover = mover->next;
    }

    while(temp2!=nullptr){
        mover->next = temp2;
        temp2 = temp2->next;
        mover = mover ->next;
    }
    //now since both the temp have been exhausted, time to move dummy to eliminate the fake header
    dummy = dummy->next;
    return dummy;
}

node* findMiddle(node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* f= head->next->next;
    node * s = head;
    while(f!=nullptr && f->next!=nullptr){
        f = f->next->next;
        s = s->next;
    }
    return s;
}


node* mergeSortLL(node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = nullptr;
    
    //now send the two halfs again, so that they come back sorted
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    
    //now that you have two sorted linked list with you, and now you want to merge them to return them as a single linked list:
    head  = mergeSortedLL(left,right);
    return head;
}

int main(){
    node* head = new node(-1);
    node* mover = head;
    cout<<endl<<"Enter the nodes : ";
    int n=0;
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover->next = temp;
            mover=mover->next;
        }
    }while(n!=100);
    head = head->next;

    cout<<endl<<"The linked list formed is : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover->next;
    }


    head = mergeSortLL(head);

    cout<<endl<<"The linked list after sorting is : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover->next;
    }

    return 0;
}
*/


//DFS and BFS algorithm
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BFS_traversal(vector<vector<int>>& adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<" ";
        q.pop();
        for(int i : adj[n]){
            if(visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void DFS_traversal(vector<vector<int>> adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            DFS_traversal(adj,i,visited);
        }
    }
}

int main(){
    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    
    
    vector<vector<int>> adj(n+1,vector<int>(0,0));  
    cout<<endl<<"Enter the edges : ";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been made


    cout<<endl<<"Enter the starting node : ";
    int x;
    cin>>x;
    //lets start with BFS
    cout<<endl<<"The BFS traversal of the graph : ";
    BFS_traversal(adj,x);

    cout<<endl<<"The DFS traversal of the graph : ";
    vector<int> visited(n+1,0);
    DFS_traversal(adj,x,visited);


    return 0;   
}*/


// kadanes algorithm
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSumSubArray(vector<int>arr){
    int maxSum =INT_MIN;
    int current =0;
    int start =0,end=0;
    for(int i=0;i<arr.size();i++){
        if(current==0){
            start = i;
        }
        current +=arr[i];
        if(current >= maxSum){
            maxSum = current;
            end = i;
        }
        if(current<0){
            current =0;
        }
    }
    return maxSum;
}

int main(){
    // finding the sub array with the maximum sum, then kadanes algorithm is used
    vector<int> arr ={2,3,-12,4,-2,15};
    //the subarray can have negative elements as well
    cout<<endl<<"The array in question : ";
    for(int i : arr){
        cout<<i<<" ";
    }
    int n = maxSumSubArray(arr);
    cout<<endl<<n<<" is the maximum sum a subarray can have from this array";

    return 0;
}
*/


//merge sort 
//1.arrays
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int first, int middle, int last){
    vector<int> temp;
    int i = first;
    int j = middle+1;
    while(i<= middle && j<= last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //now try to insert the leftover
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now since the temp vector now contains the element(sorted) from first to last, now lets start from FIRST to LAST
    for(int z = first;z<=last;z++){
        arr[z]=temp[z-first];
    }
}

void mergeSort(vector<int>& arr, int first, int last){
    if(first==last){
        return;
    }
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){

    vector<int> arr = {7,3,5,2,87,4,2,67,34,23,5,2,1,0,6,89,66,53,23,56,22,15};
    cout<<endl<<"The array before sorting : ";
    for(int x : arr){
        cout<<x<<" ";
    }

    mergeSort(arr,0,arr.size()-1);

    //after merge sort, the array becomes : 

    cout<<endl<<"The array after sorting : ";
    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}
*/

//2. Linked list sort using merge sort
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
    int val;
    node* next;
    node(int val1){
        val = val1;
        next = nullptr;
    }
};

node* findMiddle(node* head){
    node* f = head->next->next;
    node* s = head;
    while(f!=nullptr && f->next!=nullptr){
        f=f->next->next;
        s=s->next;
    }
    cout<<endl<<"middle : "<<s->val;
    return s;
}

node* mergeLL(node* h1, node* h2){
    node* dummy = new node(-1);
    node* mover = dummy;

    node* temp1 = h1;
    node* temp2 = h2;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->val <= temp2->val){
            mover->next = temp1;
            temp1 = temp1->next;
            mover = mover->next;
        }else{
            mover->next = temp2;
            temp2 = temp2->next;
            mover = mover->next;
        }
    }

    //now the turn of the non exhausted LL
    while(temp1!=nullptr){
        mover ->next = temp1;
        temp1 = temp1->next;
        mover = mover->next;
    }
    while(temp2!=nullptr){
        mover->next = temp2;
        temp2 = temp2->next;
        mover = mover->next;
    }

    //now that the linked list is merged and sorted, time for the front of the dummy node to be laid off
    dummy = dummy->next;
    return dummy;
}

node* mergeSortLL(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = nullptr;
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    //now that the left and right are SORTED (either through being single node or being sorted from perivous calls), now lets merge these left and right linked list while maintaining the sorted nature
    head = mergeLL(left,right);
    return head;
}

int main(){

    node* head = new node(-1);    
    node* mover = head;
    int n=0;
    cout<<"Enter the values (100 to exit) :--- ";
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover->next = temp;
            mover = mover->next;
        }
    }while(n!=100);

    head = head->next;
    cout<<endl<<"The formed linked list : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover->next;
    }

    //now lets sort the linked list
    head = mergeSortLL(head);

    mover = head;
    cout<<endl<<"The SORTED linked List  :-  ";
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover->next;
    }

    return 0;

}
*/


//BFS and DFS
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traversal(vector<vector<int>>& adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    //now the visited array has been formed
    queue<int> q;
    q.push(x);
    cout<<x<<" ";
    visited[x]=1;
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                cout<<i<<" ";
                visited[i]=1;
            }
        }
    }
};

void dfs_traversal(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }

}

int main(){ 

    cout<<"Enter the no of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    cout<<endl<<"Enter the edges : ";
    vector<vector<int>> adj(n+1,vector<int>(0));
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//now the adjacency list has been formed

    cout<<endl<<"The adjacency list  : ";
    for(int i=1;i<n+1;i++){
        cout<<i<<": ";
        for(auto j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the node you want to traverse the graph from : ";
    int x;
    cin>>x;

    cout<<endl<<"BFS traversal : "; 
    bfs_traversal(adj,x);

    vector<int> visited(n+1,0);
    cout<<endl<<"DFS traversal : ";
    dfs_traversal(adj,x,visited);

    return 0;
}
*/

//merge sort practice
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int first, int middle, int last){
    int p = first;
    int q = middle+1;
    vector<int>temp;
    while(p<=middle && q<=last){
        if(arr[p]<=arr[q]){
            temp.push_back(arr[p]);
            p++;
        }else{
            temp.push_back(arr[q]);
            q++;
        }
    }//now one of them has been exhausted, lets make sure the other one is exhausted too

    while(p<=middle){
        temp.push_back(arr[p]);
        p++;
    }
    while(q<=last){
        temp.push_back(arr[q]);
        q++;
    }

    //now the temp array has the sorted array, now we need to paste this sorted array into the original array from the first to the last index

    for(int i = first; i<=last ; i++){
        arr[i] = temp[i - first];
    }//now the array has been filled

}

void mergeSort(vector<int>& arr,int first, int last){
    if(first == last){
        return;
    }
    int middle = (first + last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    //now you have two sorted parts, you need to merge them
    merge(arr,first,middle,last);
}

int main(){

    vector<int> arr = {7,3,5,2,87,4,2,67,34,23,5,2,1,0,6,89,66,53,23,56,22,15};
    cout<<endl<<"The array before the sorting : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    mergeSort(arr,0,arr.size()-1);

    cout<<endl<<"Array after sorting : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}
*/


//merge sort a linked list

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public : 
    int val;
    node* next;
    //constructor
    node(int val1){
        val = val1;
        next = nullptr;
    }
};


node* findMiddle(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    node* s = head;
    node* f = head->next->next;
    while(f!=nullptr && f->next!=nullptr){
        s = s->next;
        f = f->next->next;
    }
    return s;
}

node* merge2SortedLL(node* h1, node* h2){
    node* head = new node(-1);
    node* mover = head;

    node* temp1 = h1;
    node* temp2 = h2;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->val <= temp2->val){
            mover->next = temp1;
            temp1 = temp1->next;
            mover = mover->next;
        }else{
            mover->next = temp2;
            temp2 = temp2->next;
            mover = mover->next;
        }
    }//now one of them is null, and since both ll were initially sorted, now we just have to append the ll that is left to the combined new ll

    while(temp1!=nullptr){
        mover ->next = temp1;
        temp1 = temp1->next;
        mover = mover ->next;
    }
    while(temp2!=nullptr){
        mover->next = temp2;
        temp2 = temp2->next;
        mover = mover ->next;
    }

    //now the combined ll is sorted. just remover head(-1) i.e shift head once and return
    head = head->next;
    return head;
}

node* mergeSortLL(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    node* left = head;
    node* middle = findMiddle(head);
    node* right = middle->next;
    middle ->next = nullptr;
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    head = merge2SortedLL(left,right);
    return head;
}


int main(){

    node* head = new node(-1);
    node* mover = head;

    int n = -1;
    cout<<endl<<"Enter the nodes and enter -1 to quit : ";
    cin>>n;
    do{
        node* temp = new node(n);
        mover ->next = temp;
        mover = temp;
        cin>>n;
    }while(n!=-1);
    //now that the linked list is formed, lets print it

    head = head->next;
    mover = head;

    cout<<endl<<"The linked list before sorting  : ";
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover = mover ->next;
    }

    //now lets sort the linked list

    head = mergeSortLL(head);

    cout<<endl<<"The linked list after sorting : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->val<<" ";
        mover =  mover ->next;
    }

    return 0;
}