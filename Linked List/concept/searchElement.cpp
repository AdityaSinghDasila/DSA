#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;

    // constructor
    node(int data1, node* data2){
        data=data1;
        next=data2;
    }

    node(int data1){
        data=data1;
        next=nullptr;
    }
};

bool searchLL(node* head, int n){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==n)
            return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    node* head = new node(1);
    node* temp=head;

    int i=1;
    while(i!=100){
        cin>>i;
        node* temp2= new node(i);
        temp->next=temp2;
        temp=temp2;
    }

    int n;
    cout<<endl<<"Enter the element you want to search :";
    cin>>n;
    bool ans = searchLL(head, n);
    cout<<endl<<"ans :"<<ans;

    return 0;
}