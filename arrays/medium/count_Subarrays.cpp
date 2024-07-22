/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
*/ 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subArrFreq(vector<int> arr, int k){
    map<int,int>mike;
    // {0,0,0,0,0} k=0  in this, the key in hash must have the frequency of this pSum occuring before instead of the index in prev questions, as that will give the number of sub arrays of sum k for a given x. Thus we must store the frequency of how many times did this pSum come in the hashmap.
    int freq=0,pSum=0;
    for(int i=0;i<arr.size();i++){
        pSum+=arr[i];
        int x_m_k=pSum-k;
        if(mike.find(x_m_k)!=mike.end()){
            freq = freq + mike[x_m_k];
        }
        if(x_m_k==0)
            freq++;
        mike[pSum]++;
    }
    return freq;
}

int main(){
    //this is nearly the same as the easy question where we had to find the longest subarray with give sum k
    //The general operation for sub arrays is either through HASHMAP or THROUGH TWO POINTER.
    //since the question does not state that if the arrays elements are positive or negative, we assume they can be +ve/-ve/zeros just to be safe. Thus this eliminates the two pointer method as it fails when it comes to sum of -ve elements containing subarrays.

    //thus... we'll use hash map


    vector<int> arr = {1,2,3,1,1,1,1,3,3};

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
    int ans = subArrFreq(arr,6);

    cout<<endl<<"The number of sub Arrays that have the sum of 6 : "<<ans<<endl;

    return 0;
}