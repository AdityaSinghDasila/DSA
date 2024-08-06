/*
    given an array, find the first and last ocurrence of an element
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,2,3,4,5,6,6,6,6,6,7,8,8,8,9,101,256};
    cout<<endl<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element whose first and last occurence is to be found : ";
    cin>>el;
    //LOWER BOUND
    int first =0;
    int last = arr.size()-1;
    int focc = arr.size();
    int middle = first + (last-first)/2;
    while(first<=last){
        middle=first+(last-first)/2;
        if(arr[middle]<el){
            first = middle+1;
        }
        else if(arr[middle]>=el){
            focc = middle;
            last = middle-1;
        }
    }

    int locc = arr.size();
    first =0;
    last = arr.size()-1;
    middle = first+(last-first)/2;

    while(first<=last){
        middle = first +(last-first)/2;
        if(arr[middle]<=el){
            first = middle+1;
        }
        else if(arr[middle]>el){
            locc = middle;
            last = middle-1;
        }
    }

    if(arr[focc]!=el){
        cout<<endl<<"not found";
    }else{
        cout<<endl<<"First occurence at index :"<<focc<<endl<<"Last occurence at index : "<<locc-1;
    }
    
    return 0;
}