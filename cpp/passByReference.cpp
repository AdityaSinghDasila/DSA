#include <iostream>
using namespace std;
void passByReference(int& alias){
    cout<<"address of alias: "<<&alias<<endl;
    alias=1000;
};
int main(){
    int x=10;
    cout<<"value of x: "<<x<<endl;
    cout<<"address of x: "<<&x<<endl;

    passByReference(x);

    cout<<"value of x at END: "<<x<<endl;

    return 0;
}
// when the variable is passed, then the reference variable is made at the argument which here is int& alias, thus making alias just another name for the memory location of x. so a change in alias, reflects in x, as they are the same.

