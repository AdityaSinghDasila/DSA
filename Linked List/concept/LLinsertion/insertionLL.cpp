#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    // constructor
    node(int data1){
        data=data1;
        next= nullptr;
    }
};

node* insHead(node* head, int el){
    node* temp = new node(el); 
    temp->next=head;
    head=temp;
    return head;
}

node* insert(node* head, int el, int pos){


    return nullptr;
}

int main(){ 
    node* head = new node(0);
    node* mover = head;

    for(int i = 1;i <= 5; i++){
        node* temp = new node(i);
        mover->next = temp; 
        mover=mover->next;
    }//The linked list has been made

    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    
    int el,pos;
    cout<<endl<<"Enter the element you want to insert :";
    cin>>el;
    cout<<endl<<"Enter the position you want to insert it in :";
    cin>>pos;

    if(pos==1){
        head = insHead(head,el);
    }
    else{
        head = insert(head,el,pos);
    }

    //now just print the new linked list
    mover = head;
    cout<<endl<<"The new linked list after insertion is : ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}