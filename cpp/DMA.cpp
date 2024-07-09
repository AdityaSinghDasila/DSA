//new and delete are the functions for DMA.
//after allocating the memory with new, the user must ensure to free up the memory with delete, in order to avoid memory leak
#include <iostream>
using namespace std;
int main(){
    cout<<"lets store 5 at a dynamically allocated memory(heap)"<<endl;
    int* pn= new int;
    *pn = 5; //instead you can also these in a single line : int* pn = new int(5); done, 5 is stored at location contained by pn pointer.
    cout<<"\nThe address allocated is: "<<pn<<endl;
    cout<<"\nThe number stored at that address is : "<<*pn<<endl;
    delete pn;//make sure to delete the allocated address
    return 0;
}