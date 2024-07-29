#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public : 
    int data;
    node* next;
    // constructor
    node(int data1){
        data=data1;
        next= nullptr;
    }
};

void printLL(node* head){
    node* mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}

node* delHead(node* head){
    node* temp = head;
    head = head->next;
    temp->next=nullptr;
    delete temp;
    return head;
}

node* delPos(node* head, int pos){
    if(pos==1){
        return delHead(head);
    }
    if(head==nullptr){
        cout<<endl<<"invalid";
        return nullptr;
    }
    node* mover = head;
    bool found =false;
    int count = 0;
    while(mover->next!=nullptr){
        count++;
        if(count==pos-1){
            node* temp = mover -> next;
            mover ->next =temp->next;
            delete temp;
            found=true;
            break;
        }
        mover=mover->next;
    }
    if(found==false)
    {
        cout<<"The position you entered is wrong";
    }
    return head;
}

node* delEl(node* head, int el){
    if(head->data==el)
    {   
        return delHead(head);
    }
    node* mover = head;
    bool found=false;
    while(mover->next!=nullptr){
        if(mover->next->data==el){
            node* temp = mover->next;
            mover->next=temp->next;
            delete temp;
            found = true;
            break;
        }
        mover = mover->next;
    }
    if(found == false)
    {
        cout<<"The element is not present in the LL";
    }
    return head;
}

int main(){
    node* head = new node(0);
    node* mover = head;
    for(int i =1; i<=5;i++){
        node* temp = new node(i);
        mover->next = temp;
        mover = temp;
    }//LL filled
    cout<<"The linked list initially : ";
    printLL(head);

    /* delete head */
    // head = delHead(head);
    // cout<<endl<<"After deleting the head, the linked list: ";
    // printLL(head);


    /* delete at kth element starting from 1 */
    // int pos;
    // cout<<endl<<"ENter the position you want to delete : ";
    // cin>>pos;
    // head = delPos(head,pos);
    // cout<<endl<<"The linked list now : ";
    // printLL(head);

    /* delete element el from the linked list if present */
    mover = head;
    int el;
    cout<<endl<<"Enter the element you want to delete : ";
    cin>>el;
    head = delEl(head,el);
    cout<<endl<<"The linked list :";
    printLL(head);

    return 0;
}