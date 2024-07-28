//delete the element entered by the user from the linked list
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
        next=nullptr;
    }
};


node* delHead(node* head){
   if(head==nullptr || head->next==nullptr){
        delete head;
   } 
    node* temp = head;
    head= head->next;
    delete temp;     
    return head;
}


node* delEl(node* head, int n){
    if(head->data == n){
        return delHead(head);
    }
    node* temp = head;
    node* assist = temp;
    while(temp->data!=n && temp!=nullptr){
        assist = temp;
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<" The element to delete was not found in the linked list!! ";
        return head;
    }
    assist->next = temp->next;
    temp->next=nullptr;
    delete temp;
    return head;
}

int main(){

    node* head = new node(0);
    node* mover = head;

    for(int i=1; i<=5 ;i++){
        node* temp = new node(i);
        mover->next=temp;
        mover=temp;
    }//linked list made

    cout<<"The linked list: ";
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    int n;
    cout<<endl<<"Enter the element you want to delete :";
    cin>>n;

    head = delEl(head,n);

    cout<<endl<<"the linked list after deletion :";
    mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}