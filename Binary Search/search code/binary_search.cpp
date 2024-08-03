/*
  The following is my attempt at binary search with my own recursive method. edit: IT WORKED!!

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int el,int first, int last){
    if(first>last)
        return -1;
    int middle = (first+last)/2;
    if(arr[middle]==el)
        return middle;
    if(arr[middle]>el)
        return binarySearch(arr,el,first,middle-1);
    return binarySearch(arr,el,middle+1,last);
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,100,200,201};
    cout<<endl<<"The Vector is :";
    for(int i: arr){
        cout<<i<<" ";
    }
    int el;
    cout<<endl<<"Enter the element to search: ";
    cin>>el;

    int ans = binarySearch(arr,el,0,arr.size()-1);
    if(ans>=0){
        cout<<endl<<"Element was found at index : "<<ans;
    }else{
        cout<<endl<<"The element was not found: ";
    }

    return 0;
}
*/


/*
    This is my attempt on binary search iterative method. edit : IT was  A success!!

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr = {};
    string no;
    cout<<endl<<"Enter the number you want to fill, type 'stop' to stop filling the array, also fill in a sorted manner : ";
    while(true){
        cin>>no;
        if(no == "stop"){
            break;
        }
  
            int input = stoi(no);
            arr.push_back(input);
    }
    cout<<endl<<"The array is :";
    for(int i: arr){
        cout<<i<<" ";
    }
    int el;
    cout<<endl<<"Enter the element to search in the vector: ";
    cin>>el;

    int first = 0;
    int last = arr.size()-1;
    int middle = (first+last)/2;
    int ans=-1;
    while(first<=last){
        middle=(first+last)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        if(arr[middle]>el){
            last = middle-1;
        }
        else if(arr[middle]<el)
        {
            first = middle+1;
        }
    }
    if(ans!=-1)
    {
        cout<<endl<<"The element was found at : "<<ans;
    }else{
        cout<<endl<<"The element could not be found ";
    }
    return 0;
}


*/


