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
    cout<<endl<<"The arrays before sorting : ";
    for(int i: arr){
        cout<<i<<" ";
    } 
    
    mergeSort(arr,0,arr.size()-1);
    
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