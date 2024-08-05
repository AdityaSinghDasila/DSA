#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,5,9,11,16,23,34,77,109,255}; //the array should be sorted
    cout<<endl<<"The arrays :";
    for(int i: arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element you want the upper bound of : ";
    cin>>el;

    int ans = arr.size();
    int first =0;
    int last = arr.size()-1;
    int middle = first + (last -first )/2;
    while(first<= last){
        middle = first + (last -first)/2;
        if(arr[middle]>el){
            ans = middle;
            last = middle -1;
        }
        else if(arr[middle]<=el){
            first = middle +1;
        }
    }
    if(ans!=arr.size()){
        cout<<endl<<"The upper bound is : "<<arr[ans];
    }else{
        cout<<endl<<"The upper bound was not found";
    }

    return 0;
}