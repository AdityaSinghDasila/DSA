#include <iostream>
using namespace std;
int main(){
    int x=10;
    int* px=&x;             //note the datatype of pointer depends on what type of value is held by the variable whose address this pointer will hold lmao

    cout<<"value of x: "<<x<<endl;
    cout<<"address of x: "<<&x<<endl;

    cout<<"value of pointer px: "<<px<<endl;
    cout<<"Dereferencing the pointer px: "<<*px<<endl; //this is the main use of pointers, i.e dereferencing
    return 0;
}

