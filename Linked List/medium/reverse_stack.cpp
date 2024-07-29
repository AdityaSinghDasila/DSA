/*
    reverse the data of the linked list without moving the head and tail.
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
    while(mover != nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
}

node* reverseData(node* head){
    node* mover = head;
    stack<int>steve;
    while(mover!=nullptr){
        steve.push(mover->data);
        mover=mover->next;
    }
    mover=head;
    while(mover!=nullptr){
        mover->data = steve.top();
        steve.pop();
        mover=mover->next;
    } 

    return head;
}

int main(){
    node* head = new node(0);
    node* mover = head;
    for(int i =1;i<=5;i++){
        node* temp = new node(i);
        mover -> next = temp;
        mover = mover -> next;
    }// ll made

    cout<<endl<<"The linked list : ";
    printLL(head);

    head = reverseData(head);
    cout<<endl<<"Reversed Linked list :";
    printLL(head);

    return 0;
}