#include <iostream>
using namespace std;
void passArr(int arr[]){
    cout<<&arr<<endl;
}//also, when you write an argument in the function parameter, an array should be shown as datatype arrname[]
int main()
{
    //when we pass an array into a function, what are we acutally passing? an array or a pointer? //answer is the array is decayed into a pointer.
    int arr[]={1,2,3,4};
    cout<<"Address of original array: "<<&arr<<endl;
    passArr(arr);
    return 0;
}
/*
paste above code into the cppinsights.io
*/

/*
void passArr(int * arr)
{
  std::cout.operator<<(reinterpret_cast<const void *>(&arr)).operator<<(std::endl);
}
this is what becomes of the original function code.

explanation: void passArr(int arr[]) ---> void passArr(int* arr) is a copy of the pointer of the original array, but even after being a copy, it is still pointing to the original array.
thus, pass by value is difficult in arrays as the passed array is DECAYED into a pointer in the function.
*/