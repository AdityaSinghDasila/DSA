#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bubble(vector<int>& arr){
    //comparision in the pair, and this comparision moves forward with swaps, pushing the largest at the endd
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    vector<int>arr ={323,23,1,23,51,2,31,34,2,1,23523,53,2123,1,1,21,1,0};
    cout<<"The vector before sorting: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
    
    bubble(arr);
    
    
    cout<<endl<<"The Vector after sorting : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}