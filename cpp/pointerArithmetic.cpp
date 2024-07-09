#include <iostream>
using namespace std;
int main(){
    //when we increase a pointer by one, the pointer moves forward by the size of block of data it points to, for example, if a pointer is of int type (which means it points to an int data), if i increment the pointer by one, it moves 4bytes forward. The following is a demonstration:-
    int arr[]={1,2,3,4};
    int* parr= arr; //as arr contains the starting address of the array

    cout<<"Address of *parr: "<<parr<<endl;
    cout<<"Value of *parr: "<<*parr<<endl; 

    //lets increment the pointer that points to the start of the array by one.
    parr++;

    cout<<"Address of *parr after increment : "<<parr<<endl;
    cout<<"Value of *parr after increment : "<<*parr<<endl;

    //now lets traverse over the array by this method
    cout<<"value of *parr 2: "<<*(parr+1)<<endl;//as par was at 1 already due to parr++
    cout<<"value of *parr 3: "<<*(parr+2)<<endl;

    return 0;
}
/*
Address of *parr: 0x78fe00
Value of *parr: 1
Address of *parr after increment : 0x78fe04
Value of *parr after increment : 2
*/
//you can see above that the address changed by 4 byte (size of int).