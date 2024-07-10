#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    //this is to show you that sizeof should not be used to calculate how many elements are there in a DS. 
    int x=10;
    int* px=&x;
    int arr[]={1,2,3,4,5};//stack allocated
    int* darr= new int[7];//heap allocated
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    cout<<"The sizes calculated by sizeof operator: "<<endl;
    cout<<"sizeof          x: "<<sizeof(x)<<endl;
    cout<<"sizeof         px: "<<sizeof(px)<<endl;
    cout<<"sizeof arr  array: "<<sizeof(arr)<<endl;
    cout<<"sizeof darr array: "<<sizeof(darr)<<endl;//what you'll see is this will output the size of pointer as darr is a pointer only
    cout<<"sizeof          v: "<<sizeof(v)<<endl;
    return 0;
}
/*
The sizes calculated by sizeof operator: 
sizeof          x: 4
sizeof         px: 8
sizeof arr  array: 20
sizeof darr array: 8
sizeof          v: 24
*/
 
 /*
 Observations:
 in sizeof pointer, it'll be same for the system which is 8bytes here.
 in sizeof array, there are 5 elements, 5x4bytes=20 which is printed.
 in sizeof darr, since darr is a pointer that points to the heap location where the actual array is, the sizeof darr is 8bytes, which is pointer's  typicall size.
 in sizeof v(a vector), the size is 24 bytes, 24/4=6 elements? but there are 7 elements pushed, this happens because sizeof() only returns the size of the DATASTRUCTURE, which here is the size of the vector here.(STL must be using some algo for this to make sense lmao)
 IF you want to find the number of elements in the vector, you'll have to use v.size()


 THUS, the main point to take home is that sizeof function should not be used to calculate the number of elements of a DATASTRUCTURE
 */