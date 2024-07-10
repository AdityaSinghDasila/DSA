#include <iostream>
using namespace std;
int main(){
    int *ptr = new int[5];
    delete ptr; // here the program is correct
    // delete ptr; now the program is wrong as this is the case of double free
    return 0;
}

/*
    1.Memory leak is when a user, after DMA, forgets to free the memory allocated and also loses any pointers that were pointing to that heap location, THUS loosing any hope of freeing that memory further.
    Now the program will not be able to access that memory as memory manager will deem that Heap memory as reserved.(so neither the user, nor the program can now access that heap memory... thus that memeory is referred to as LEAKED MEMORY)
*/

/*
    2.Double free is when you free the HEAP allocated memory not once, but TWICE!! 
    in the first delete pointer; --> you free the heap memory and the memory manager places that memory in its own manager data structure.
    in the second delete pointer; --> the DS maintained by memory manager is deemed to be corrupted or something.. ultimately the behaviour is UNDEFINED!!
*/
