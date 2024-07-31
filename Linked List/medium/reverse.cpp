/*
    traversal order of linked list is reverse, without moving the actual data, i.e head and tails are reversed
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    // constructor
    node(int data1){
        data= data1;
        next = nullptr;
    }
};

void printLL(node* head){
    node* mover = head;
    while(mover!= nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
}

node* reverseLL(node* head){
    node* temp = nullptr;
    node* mover = head;
    node* temp2 = nullptr;
    while(mover != nullptr){
        temp2=mover->next;
        mover->next=temp;
        temp = mover;
        mover = temp2;
    }
    head = temp;
    return head;
}

node* reverseRecursion(node* head,node* temp){
    if(head==nullptr){
        cout<<endl<<"HAHA";
        return temp;
    }
    node* temp2= head->next;
    head->next=temp;
    temp = head;
    head = temp2;
    return reverseRecursion(head,temp);
}


/*********************************************************************** */
int main(){
    node* head = new node(0);
    node* mover = head;
    for(int i=1;i<=5;i++){
        node* temp = new node(i);
        mover->next = temp;
        mover= mover -> next;
    }//ll made

    cout<<endl<<"linked list before operation : ";
    printLL(head);

    // head = reverseLL(head);
    head = reverseRecursion(head,nullptr);
    cout<<endl<<"Reversal of linked list through itrative method :";
    printLL(head);

    return 0;
}