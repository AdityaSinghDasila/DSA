#include <iostream>
using namespace std;
void valueOp(int args){
    cout<<"initial value of args: "<<args<<endl;
    args=1000;
    cout<<"Final value of args: "<<args<<endl;
    cout<<"Adress of args: "<<&args<<endl;
};
int main(){
    int x=10;
    cout<<"Value of x: "<<x<<endl;
    cout<<"address of x : "<<&x<<endl;
    valueOp(x); //only the value is sent
    cout<<"Value of x: "<<x<<endl;
    cout<<"address of x: "<<&x<<endl;
    return 0;
}

//you'll see that the address of x is different from the address of args, this also proves that args is a different variable who has the value of x but not does not share the same address as x, so a change in args does not reflect on the variable x.