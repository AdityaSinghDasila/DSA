#include <iostream>
using namespace std;
int main(){
    int n=0;
    cout<<"Enter the size of array you want to allocate in heap memo: ";
    cin>>n;
    int* parr = new int[n];
    for(int i=0;i<n;i++){
        parr[i]=i;
    }
    cout<<"The array is : ";
    for(int i=0;i<n; i++){
        cout<<parr[i]<<" ";
    }

    cout<<"\nNow to delete the array"<<endl;
    delete[] parr;//delete will have [] only when you have allocated memory using new [] like above. if you only use delete, the behaviour is undefined.

    return 0;
}