/*
    sort a linked list
*/
//the easy way is to copy the elements into an array and then sort the array. after that convert the array to a linked list; TC O(n) SC O(n)
// we can also apply merge sort on the linked list
/*
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

node* merge2SortedLL(node* head1, node* head2){
    node* head = new node(-1);
    node* mover = head;
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<= temp2->data){
            mover->next = temp1;
            temp1=temp1->next;
            mover = mover->next;
        }
        else{
            mover->next = temp2;
            temp2=temp2->next;
            mover = mover->next;
        }        
    }
    while(temp2!=nullptr){
        mover->next=temp2;
        mover = temp2;
        temp2=temp2->next;
    }
    while(temp1!=nullptr){
        mover->next = temp1;
        mover = temp1;
        temp1 = temp1->next;
    }
    return head->next;
}

node* findMiddle(node* head){
    node* fast = head->next->next;
    node* slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeSort(node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    node* middle = findMiddle(head);
    node* rightHead = head;
    node* leftHead = middle->next;
    middle->next = nullptr;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    node* newHead = merge2SortedLL(leftHead,rightHead );
    return newHead;

}
int main(){
    //lets create linked list
    node* head = new node(0);
    node* mover = head;
    cout<<"Enter elements (enter 100 to stop though): ";
    int n = 0;
    while(n!=100){
        cin>>n;
        node* temp = new node(n);
        mover ->next = temp;
        mover= mover ->next;
    }
    if(head!=nullptr)
        head = head->next;
    cout<<endl<<"The linked list : ";
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover = mover->next;
    }   
    head =  mergeSort(head);
    cout<<endl<<"The sorted linked list : ";
    mover = head;
    while( mover != nullptr){
        cout<<mover->data<<" ";
        mover= mover-> next;
    }
    return 0;
}
*/