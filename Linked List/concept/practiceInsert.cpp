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
        next = nullptr;
    }
};

void printLL(node* head){
    node* mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}

node* insHead(node* head, int el){
  
    node* temp = new node(el);
    if(head==nullptr){
        return temp;    
    }
    temp->next= head;
    head = temp;
    return head;
}

node* insPos(node* head, int el, int pos){
    if(pos==1){
        return insHead(head,el);
    }
    node* temp = new node(el);
            if(head == nullptr){
                if(pos==1)
                {
                    return temp;
                }   
                else{
                    cout<<"invalid";
                    return nullptr;
                }
            }
    int current =0;
    node* mover = head;
    bool valid = false;
    while(mover->next!=nullptr){
        current++;
        if(current==pos-1){
            temp->next = mover -> next;
            mover->next = temp;
            valid = true;
            break;
        }
        mover = mover->next;
    }
    if(current+1==pos-1){
        mover->next = temp;
        valid = true;
    }
    if(valid==false)
    {
        cout<<"The position is out of bounds of linked list";
    }
    return head;
}

int main(){
    node* head = new node(0);
    node* mover = head;
    
    for(int i=1;i<=5;i++){
        node* temp = new node(i);
        mover->next = temp;
        mover = temp;
    }//linked list filed

    cout<<endl<<"Linked list :";
    printLL(head);
    
    // /* Insert a new head */
    // int el;
    // cout<<endl<<"Enter the element to insert at the begining :";
    // cin>>el;
    // head = insHead(head,el);
    // cout<<endl<<"Linked List :";
    // printLL(head);


    /*  Insert at kth position, the first poistion beign 1 */
    int pos,el;
    cout<<endl<<"Enter the element to enter :";
    cin>>el;
    cout<<endl<<"Enter the position you want to fill the element in :";
    cin>>pos;
    head = insPos(head,el,pos);
    cout<<endl<<"The linked list: ";
    printLL(head);

    return 0;
}