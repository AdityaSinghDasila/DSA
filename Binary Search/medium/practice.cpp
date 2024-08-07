#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={10,10,10,10,10,10,10,10,10,10,10,10,11,12,13,14,15,16,17,18,19,20,21,1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    for(int i : arr){
        cout<<i<<" ";
    }
    
    cout<<endl<<"Enter the element you want the to return the index of : ";
    int el;
    cin>>el;

    int first =0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first + (last-first)/2;
    while(first<=last){
        middle = first +(last -first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        else if(arr[first]== arr[middle] && arr[last]==arr[middle]){
            first = first +1;
            last = last -1;
        }
        else if(arr[first]<=arr[middle]){
            //left is sorted
            if(el>=arr[first] && el<arr[middle]){
                last = middle -1;
            }
            else{
                first = middle+1;
            }
        }
        else{
            //right is sorted
            if(el>arr[middle] && el<=arr[last]){
                first = middle +1;
            }
            else{
                last = middle-1;
            }
        }
    }

    if(ans!=arr.size()){
        cout<<endl<<"The index of element in the array is : "<<ans;
    }    
    else{
        cout<<endl<<"The element was not found!! ";
    }

    return 0;
}