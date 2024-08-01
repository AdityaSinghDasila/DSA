#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* next;
    // constructor
    node(int data1){
        data =data1;
        next = nullptr;
    }
};


node* mergeLL(node* head1, node* head2){
    node* head = new node(-1);  
    node* mover = head;
//now lets make two pointers
    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1!= nullptr && temp2!=nullptr){
        if(temp1->data<=temp2->data){
            mover->next = temp1;
            mover = mover->next;
            temp1=temp1->next;
        }
        else{
            mover->next = temp2;
            mover = temp2;
            temp2=temp2->next;
        }
    }
    //now joining any of them that did not reach null and has nodes left to join 
    while(temp1!=nullptr){
        mover->next = temp1;
        mover = temp1;
        temp1=temp1->next;
    }
    while(temp2!=nullptr){
        mover->next=temp2;
        mover = temp2;
        temp2= temp2->next;
    }
    return head->next;
}


int main(){
    //lets create two sorted linked lists
    node* head1 = new node(11);
    node* mover = head1;
    for(int i=12;i<=20;i++){
        node* temp = new node(i);
        mover -> next = temp;
        mover = mover->next;
    }
    mover = head1;
    cout<<endl<<"The first sorted linked list is : ";
    while(mover!= nullptr){
        cout<<mover->data<<" ";
        mover= mover ->next;
    }



    node* head2= new node(0);
    mover = head2;
    for(int i =1;i<=40;i++){
        node* temp = new node(i);
        mover->next = temp;
        mover= mover ->next;
    }
    mover = head2;
    cout<<endl<<"The second sorted linked list is : ";
    while(mover!= nullptr){
        cout<<mover->data<<" ";
        mover= mover->next;
    }

    //now lets merge these two linked list with SC of O(1)
    node* head = mergeLL(head1, head2);
    cout<<endl<<"The SORTED LINKED LIST : ";
    mover = head;
    while(mover!= nullptr){
        cout<<mover->data<<" ";
        mover= mover->next;
    }
    return 0;
}