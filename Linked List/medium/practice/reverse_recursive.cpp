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

node* reverseLL(node* head){
    if(head==nullptr || head->next== nullptr){
        return head;
    }
    node* newHead = reverseLL(head->next);
    node* front = head->next;
    head->next=nullptr;
    front->next=head;
    return newHead;
}

int main(){
    node* head = new node(0);
    node* mover = head;
    for(int i=1;i<=10;i++){
        node* temp = new node(i);
        mover -> next = temp;
        mover = mover -> next;
    }
    cout<<endl<<"The linked list : ";
    mover = head;
    while(mover != nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    head = reverseLL(head);
    cout<<endl<<"The reversed linked list: ";
    mover = head;
    while(mover!= nullptr){
        cout<<mover->data<<" ";
        mover= mover ->next;
    }
    return 0;
}