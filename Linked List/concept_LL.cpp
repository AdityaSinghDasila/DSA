#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//making a linked list 
//use class instead of struct because of added functionalities like abstraction, encapsulation etc in class
class Node{
    public: 
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    //another constructor in case you dont want to type nullptr always
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};




int main(){
    //after class made, we use new method to allocate the custom datatype to a heap memory and the address is returned;
//1st method using object
    Node head = Node(100,nullptr);
    cout<<"accesing data using . operator :"<<head.data<<endl;
    cout<<"The address of head using &head :"<<&head;
    

//2nd method using new (preffered)    
    Node* head2 = new Node(10,nullptr);
    cout<<endl<<endl<<"The data contained in Node pointed by head2 :"<<head2->data;
    cout<<endl<<"The address of head2 :"<<head2;


//using the second constructor
    Node * head3= new Node(69);
    cout<<endl<<"The data contained in node pointed by head3 :"<<head3->data;
    cout<<endl<<"The address of Node pointed by head3 :"<<head3;
    return 0;
}