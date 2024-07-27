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

node* delTail(node* head){

    node* temp =head;
    while(temp!=nullptr){
        if(temp->next->next==nullptr){
            node * last= temp->next;
            temp->next=nullptr;
            delete last;
        }
        temp=temp->next;
    }
    return head;
}

int main(){

    node* head = new node(0);
    node* mover= head;

    for(int i=1;i<=5;i++){
        node* temp = new node(i);
        mover->next= temp;
        mover=mover->next;
    }

    cout<<"The Linked list initilly :";
    mover=head;
    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    head= delTail(head);

    cout<<endl<<"Linked list after :";
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}