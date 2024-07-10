#include <iostream>
using namespace std;
int* foo(){
    int x=10;
    int* fooptr=&x;
    return fooptr;
}
int main(){
    int* ptr= nullptr; //null pointer for initialisation, you can also do NULL, but nullptr is better idk..
    *ptr = 42; //segmentation fault core dumped due to dereferencing a NULL pointer.
    ptr=foo();    //DANGLING pointer

    return 0;
}

/*
    1.Dereferencing a nullptr is a pitfall of pointer. It leads to segmentation fault core dumped.
*/


/*
    2.A dangling pointer is a pointer which was once pointing to a data that now no longer exists.
    in the above example:
    fooptr pointer is returned, which holded the location of stack allocated local variable x. once the function called is finished, x is removed from stack. thus, now ptr holds location of data that does not exists.lmao.
*/