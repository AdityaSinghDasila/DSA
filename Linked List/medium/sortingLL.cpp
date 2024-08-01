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

node* mergeSort(node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
}

int main(){
    node* head = new node(0);
    node* mover = head;
    cout<<"enter elements, enter 100 to stop";
    int n;
    while(n!=100){
        cin>>n;
        node* temp = new node(n);
        mover->next = temp;
        mover = temp;
    }
    cout<<endl<<"The Linked list formed is : ";
    mover =head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }


    //now we will apply merge sort to this linked list
    head = mergeSort(head);
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover= mover ->next;
    }
    return 0;
}