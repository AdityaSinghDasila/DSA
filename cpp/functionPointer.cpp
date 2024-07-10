#include <iostream>
using namespace std;
int add(int n1,int n2){
    return n1+n2;
}
int main(){
int (*op)(int,int);
op=add;
cout<<op(1,2)<<endl;
}
/*
POINTERS HOLD THE ADDRESS OF VARIABLES. FUNCTIONS ALSO HAVE ADDRESSES, SO FUNCTION POINTERS ARE MADE TO HOLD THE ADDRESSES OF FUNCTIONS.
    In order to create a pointer for a function, 
    the syntax of the function must be copied: int __(int,int);
    now make a pointer:
    int (*ptr){int,int};

    now assign the pointer to the function:
    ptr=function_name;
    now you can call the function with the pointer
    ptr(n1,n2);
*/