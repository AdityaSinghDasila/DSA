/*
    floor of an element el is the largest element which is smaller or equal to el in the array
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,5,9,11,16,23,34,77,109,255};
    cout<<endl<<"The array :";
    for(int i:arr){
        cout<<i<<" ";
    }
    int el;
    cout<<endl<<"Enter the element you want the upper bound of form the array: ";
    cin>>el;

    int first= 0;
    int last = arr.size()-1;
    int middle = first +(last-first)/2;
    int ans =-1;
    while(first<=last){
        int middle = first +(last-first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        if(arr[middle]<el){
            if(middle>ans){
                ans = middle;
            }
            first = middle +1;
        }
        else if(arr[middle]>el){
            last = middle -1;
        }
    }
    
    if(ans != -1){
        cout<<endl<<"The floor of "<<el<<" was found at index "<<ans<<" which is "<<arr[ans];
    }else{
        cout<<"The floor of "<<el<<" was not found";
    }

    return 0;
}