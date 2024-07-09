#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int* ptr=arr;
    //instead of using *(ptr+0/1/2/3/4), we'll use arr, as it also holds the starting address of array
    cout<<"Value of arr[0]: "<<arr[0]<<endl;
    cout<<"Value of arr[1]: "<<arr[1]<<endl;
    cout<<"Value of arr[2]: "<<arr[2]<<endl;
    cout<<"Value of arr[3]: "<<arr[3]<<endl;
    cout<<"Value of arr[4]: "<<arr[4]<<endl; // thus, the [i] work as easy method to dereference and do pointer addition
    
    return 0;
}