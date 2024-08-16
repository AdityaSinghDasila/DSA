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

