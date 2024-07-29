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
    if(head == nullptr){
        if(pos==1)
            return new node(el);
    }
    if(pos==1){
        node* newh = new node(el);
        newh->next = head;
        head = newh;
        return head;
    }
    int count = 1;
    node* mover = head;
    while(count!=pos-1){
        if(mover==nullptr)
        {
            cout<<endl<<" not valid ";
            return nullptr;
        }
        mover=mover->next;
        count++;
    }
    node* newnode = new node(el);
    newnode->next=mover->next;
    mover->next = newnode;

    return head;
}


node* insertBeforeEl(node* head, int el, int bef){
    if(head->data == bef){
        node* temp = new node(el);
        temp->next = head;
        head = temp;
        return head;
    }
    bool found =false;
    node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data==bef){
            node* newnode = new node(el);
            newnode->next = temp->next;
            temp->next = newnode;
            found =1;
            return head;
        }
        temp=temp->next;
    }
    if(found==false)
    {
        cout<<endl<<"Not present in LL ";
    }
    return head;
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
    /* inserting an element at a position */
    // int el,pos;
    // cout<<endl<<"Enter the element you want to insert :";
    // cin>>el;
    // cout<<endl<<"Enter the position you want to insert it in :";
    // cin>>pos;

    // if(pos==1){
    //     head = insHead(head,el);
    // }
    // else{
    //     head = insert(head,el,pos);
    // }

    // //now just print the new linked list
    // mover = head;
    // cout<<endl<<"The new linked list after insertion is : ";
    // while(mover!=nullptr){
    //     cout<<mover->data<<" ";
    //     mover=mover->next;
    // }


    /* inserting an element before already existing element */
    int bef,el;
    cout<<endl<<"Enter the element before which you want to insert : ";
    cin>>bef;
    cout<<endl<<"Enter the element : ";
    cin>>el;
    head = insertBeforeEl(head,el,bef);

    cout<<endl<<"The new linked list after insertion is : ";
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}