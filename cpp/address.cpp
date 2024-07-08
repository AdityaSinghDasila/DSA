#include <iostream>
using namespace std;
void foo(){
    cout<<"haha";
};
int main()
{
    int x=10;
    float y=5;
    char a='1';
    signed char  b = 'w';


    // now lets print the address of these using the & operator: 
    cout<<"address of x: "<<&x<<endl;
    cout<<"address of y: "<<&y<<endl;
    cout<<"address of a: "<<(void*)&a<<endl;//
    cout<<"address of b: "<<(void*)&b<<endl;
    cout<<"address of foo: "<<&foo<<endl;
    return 0;
}