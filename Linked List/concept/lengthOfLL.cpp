#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    //constructors
    node(int data1, node* data2){
        data=data1;
        next=data2;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }
};

int lengthOfLL(node* head){
    int count=0;

    node* temp=head;
    count=1;
    temp=temp->next;


    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    

    return count;
}

int main(){

    node* head = new node(100);
    node* mover=head;

    for(int i=1;i<=5;i++){
        node* temp = new node(i+100);
        mover->next=temp;
        mover=mover->next;
    }
    
    cout<<endl<<"Linked list is : ";
    node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    int len = lengthOfLL(head);
    cout<<endl<<"Length of linked list : "<<len<<endl;

    
    return 0;
}