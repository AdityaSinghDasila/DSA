/*
    Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/
//brute force, i can use hashmap and store node* address in one pass on a ll, then check every node* address from the hashmap on the second ll traversal, and once a match is made, the node in question is the intersection node between the two ll.This method uses 2 passes and a space complexity of O(N)

//we will use another algo for this though

//once a header of one linked list reaches the end node, i will send that header two the header of the 2nd ll, and when the header of 2nd ll reaches the end, i will send him to the header of the 1st ll.
//at this moment, both the headers will definitely be pointing at the intersection node

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

node* intersect(node* head1, node* head2){
    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1!=temp2){
        if(temp1==nullptr || temp1->next==nullptr){
            temp1=head2;
        }
        if(temp2==nullptr || temp2->next == nullptr){
            temp2=head1;
        }
        else{
            temp1=temp1->next;
            temp2= temp2->next;
        }
    }

    return temp1;
}

int main(){
    node* head1 = new node(-1);
    node* mover = head1;

    cout<<"Enter the nodes of the first linked list (at least 5): ";
    int n;
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover ->next = temp;
            mover = mover ->next;
        }
    }while(n!=100);
    


    cout<<endl<<"Now enter the second linked list : ";
    node* head2 = new node(-1);
    node* mover2 = head2;
    do{
        cin>>n;
        if(n!=100){
            node* temp = new node(n);
            mover2 ->next = temp;
            mover2 = temp;
        }
    }while(n!=100);
    
    head1 = head1->next;
    mover=head1;
    int count=0;
    while(mover!=nullptr){
        count++;
        if(count==5){
            break;
        }
        mover=mover->next;
    }

    mover2->next = mover;
    
    
    
    
    cout<<endl<<"The first linked list : ";
    mover = head1;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover = mover ->next;
    }
    head2=head2->next;
    mover2=head2;
    cout<<endl<<"The second ll : ";
    while(mover2!=nullptr){
        cout<<mover2->data<<" ";
        mover2 = mover2->next;
    }

    node* ans = intersect(head1, head2);
    
    cout<<endl<<"The node of intersection is : "<<ans->data;

    return 0;
}