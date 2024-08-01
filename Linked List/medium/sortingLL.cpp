//please practice this as much as possible also.
//dont forget to dry run too

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

node* findMiddle(node* head){
    //tortoise and hare algo
    node* fast = head->next->next;
    node* slow = head;
    while(fast!=nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node* merge2SortedLL(node* head1, node* head2){
    node* head = new node(-1);
    node* temp1= head1;
    node* temp2 = head2;
    node* mover = head;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<=temp2->data){
            mover->next = temp1;
            mover = temp1;
            temp1 = temp1->next;
        }
        else{
            mover->next = temp2;
            mover = temp2;
            temp2 = temp2->next;
        }
    }
    while(temp1!=nullptr){
        mover->next = temp1;
        temp1=temp1->next;
        mover=mover->next;
    }
    while(temp2!=nullptr){
        mover->next = temp2;
        temp2 = temp2->next;
        mover = mover->next;
    }
    return head->next;
}

node* mergeSort(node* head){
    if(head==nullptr || head->next == nullptr){
        // cout<<"haha"<<endl;
        return head;
    }
    node* middle = findMiddle(head);
    node* leftHead = head;
    node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge2SortedLL(leftHead,rightHead);
}

int main(){
    node* head = new node(0);
    node* mover = head;
    cout<<"enter elements, enter 100 to stop : ";
    int n;
    while(n!=100){
        cin>>n;
        node* temp = new node(n);
        mover->next = temp;
        mover = temp;
    }
    head=head->next;
    cout<<endl<<"The Linked list formed is : ";
    mover =head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }


    //now we will apply merge sort to this linked list
    head = mergeSort(head);
    mover = head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover= mover ->next;
    }
    return 0;
}