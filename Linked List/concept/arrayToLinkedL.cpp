#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//create class for this:
class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data1, node* data2){
        data=data1;
        next=data2;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }//i'll mostly use this
};

node* arrayToLl(vector<int> arr){
    //lets make the head node which will contain the first element of the vector
    node* head = new node(arr[0]);
    node * mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next= temp;
        mover=temp;
    }
    return head;
}

int main(){

    vector<int> arr= {1,2,3,4,5,6,7,8,9,10};
    cout<<"The array traversal :";
    for(int i: arr){
        cout<<i<<" ";
    }

    node* head = arrayToLl(arr);

    cout<<endl<<"The linked list traversal :";
    node* mover= head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }

    return 0;
}