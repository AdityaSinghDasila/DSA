#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    vector<int> arr ={4,5,6,7,0,1,2};
    cout<<endl<<"The array : ";
    for(int i: arr){
        cout<<i<<" ";
    }
    
    int el;
    cout<<"Enter the element you want the index of : ";
    cin>>el;
    int first = 0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first + (last - first)/2;

    while(first<=last){
        middle = first + (last-first)/2;
        if(arr[middle]==el)
        {
            ans = middle;
            break;
        }
        //side decide
        if(arr[middle]>=arr[first])
        {
            if(arr[first]<=el && arr[middle]>=el){
                last = middle-1;
            }
            else{
                first = middle+1;
            }
        }
        else{
            //right side sorted
            if(el<=arr[last] && el>=arr[middle]){
                first = middle+1;
            }
            else{
                last = middle-1;
            }
        }
    }
    cout<<endl<<"ans = "<<ans;
    return 0;   
}