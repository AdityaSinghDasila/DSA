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
        next=nullptr;
    }
};

void printLL(node* head){
    node * temp = head;
    cout<<"The linked list :";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* delHead(node* head){
    if(head==nullptr || head->next==nullptr){
        delete head;
        cout<<"if was called";
        return nullptr;
    }
    cout<<"i was called";
    node* temp = head;
    head=head->next;
    delete temp;
    return head;
}

node* delKth(node* head, int k){
    if(k==1){
        return delHead(head);
    }
    else{
        node* mover= head;
        node* assist = mover;
        int count =1;
        while(count!=k){
            assist = mover;
            mover=mover->next;
            count++;
            if(mover==nullptr){
                cout<<endl<<"The index is not present !!";
                return nullptr;
            }
        }
        assist->next = mover->next;
        mover->next=nullptr;
        delete mover;

        return head;
    }
}


int main(){

    node* head = new node(0);
    node* mover=head;

    for(int i=1;i<=5;i++){
        node* temp = new node(i);
        mover->next= temp;
        mover=temp;
    }//linked list made
    
    printLL(head);

    int k;
    cout<<endl<<"position of element (1 indexed L.L) you want to delete :";
    cin>>k;
    head = delKth(head,k);

    cout<<endl<<"The new linked list after Deletion: ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}