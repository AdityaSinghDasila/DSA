/*
    The lower bound for a given no in a sorted array is the FIRST NO that is equal to or greater than the given number than the array
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
    cout<<endl<<"Enter the element for which you want to find the lower bound for :";
    cin>>el;

    int ans = arr.size();
    int last=arr.size()-1;
    int first = 0;
    int middle = first +(last-first)/2;
    while(first<=last){
        int middle = first+ (last-first)/2;
        if(arr[middle]==el){
            ans= middle;
            break;
        }
        if(arr[middle]>el){
            if(middle<ans){
                ans = middle;
            }
            last = middle -1;
        }
        else if(arr[middle]<el){
            first = middle +1;
        }
    }
    if(ans!=arr.size()){
        cout<<endl<<"The lower bound of "<<el<<" int the array is "<<arr[ans]<<" at index "<<ans;
    }else{
        cout<<endl<<"The lower bound for "<<el<<"  is not present in the array yet";
    }
    return 0;
}