#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // constructor
    node(int data1, node* data2){
        data=data1;
        next=data2;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }
};

node* delHead(node* head){
    node* temp = head;
    head=head->next;
    delete temp;
    return head;
}//O(1)

int main(){
    node* head= new node(0);
    node* mover= head;

    for(int i=1;i<5;i++){
        node* temp = new node(i);
        mover->next=temp;
        mover=mover->next;
    }
    
    cout<<"Linked list before deletion : ";
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    head = delHead(head);
    mover=head;
    cout<<endl<<"Linked list after deletion of head: ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}