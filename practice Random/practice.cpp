//Merge sort: 1. arrays
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int first, int middle, int last){
    //keeping starting pointer for both the sorted virtual arrays
    int i=first;
    int j=middle+1;
    vector<int> temp;
    while(i<=middle && j<=last){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //measures to ensure both the virtual arrays have been cooked
    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=last){
        temp.push_back(arr[j]);
        j++;
    }
    //now that both have been cooked and placed inside temp, transfer temp to arr
    for(int i = first;i<=last;i++){
        arr[i]= temp[i-first];
    }
}

void mergeSort(vector<int>& arr,int first, int last){
    if(first>=last)
        return;
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

int main(){
    vector<int> arr ={9,2,45,2,1,67,87,45,32,12,5,1,0,4,33,45,6,7,89,9,3,5,4};
    cout<<endl<<"The arrays before sorting : ";
    for(int i: arr){
        cout<<i<<" ";
    } 
    
    mergeSort(arr,0,arr.size()-1);
    
    cout<<endl<<"The array after sorting : ";
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;
}
*/

