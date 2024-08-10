/*
    SORT 0,1 AND 2 BY CHANGIN LINKS
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
        data = data1;
        next = nullptr;
    }
};

node* sort012(node* head){
    node* temp = head;

    node* dum0 = new node(-1);
    node* mov0 = dum0;

    node* dum1 = new node(-1);
    node* mov1 = dum1;

    node* dum2 = new node(-1);
    node* mov2 = dum2;

    while(temp!=nullptr){
        if(temp->data==0){
            mov0->next = temp;
            temp = temp->next;
            mov0 = mov0->next;
            mov0->next = nullptr;
        }
        else if(temp->data==1){
            mov1->next = temp;
            temp = temp->next;
            mov1 = mov1->next;
            mov1->next = nullptr;
        }
        else if(temp->data==2){
            mov2->next = temp;
            temp = temp->next;
            mov2 = mov2->next;
            mov2->next = nullptr;
        }
    }

    mov1->next = dum2->next;
    mov0->next = dum1->next;
    head = dum0->next;

    return head;
}

int main(){
    //making the linked list
    node* head = new node(-1);
    cout<<"Enter the nodes of 0,1,2 in any order : ";
    node* mover = head;
    int n;
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover ->next = temp;
            mover = mover ->next;
        }
    }while(n!=100);
    cout<<endl<<"The linked list formed : ";
    head = head->next;
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    


    //function call
    head = sort012(head);

    //printing sorted ll
    cout<<endl<<"Linked List after sorting : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover = mover ->next;
    } 

    return 0;
}