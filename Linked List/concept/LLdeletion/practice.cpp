//make functions to delete head and tail
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    //constructor 
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
    if(head==nullptr || head->next==nullptr){
        delete head;
        return nullptr;
    }
    node* temp = head;
    head=head->next;
    delete temp;
    return head;
}

node* delTail(node* head){
    node* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    node* tail = temp->next;
    delete tail;
    temp->next=nullptr;
    return head;
}

int main(){

    node* head= new node(0);
    node* mover= head;

    for(int i=1;i<=5;i++){
        node* temp = new node(i);
        mover->next=temp;
        mover=mover->next;
    }//the linked list has been made
 
//    //head deletion part: 
//     head = delHead(head);
//     mover=head;
//     cout<<endl<<"The linked list after head deletion : ";
//     while(mover!=nullptr){
//         cout<<mover->data<<" ";
//         mover=mover->next;
//     }


    //tail deletion part :
    cout<<endl<<"The linked list after tail deletion : ";
    head= delTail(head);
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}