/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    for testing:
    use these arrays:
    1. [100,4,200,1,3,2]        expect output : 4
    2. [0,3,7,2,5,8,4,6,0,1]    expect output : 9
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int better(vector<int> nums){
    sort(nums.begin(),nums.end());
    int count =1,maxc=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]+1){
            count++;
        }
        if(nums[i]==nums[i-1]){

        }
        else{
            maxc = max(maxc,count);
            count=1;
        }
    }
    return maxc;
}


int optimal(vector<int> arr){
    unordered_set<int> setto;
    for(int i : arr ){
        setto.insert(i);
    }//the set has been filled, unsorted but unique only
    int maxLen =0; 
    // printing set
    
    for(int i : setto){
        cout<<endl<<"set element : "<<i;
        if(setto.find(i-1)==setto.end()){
            int count= 1;
            int x = i;
            while(setto.find(x+1)!=setto.end()){
                count++;
                x=x+1;
            }
            maxLen= max(maxLen, count);
        }
    }  
    return maxLen;
    /*
        TC : O(2N)==O(N)'
        SC : O(N)
    */ 
}

int main(){

    vector<int> nums = {100,4,200,1,3,2,2,5,5,6};
    cout<<endl<<"The array : ";
    for(int i : nums){
        cout<<i<<" ";
    }
    //brute force is garbage so i skipped, it had TC of O(N^3) and SC of O(1)
    //moving to the better approach
    int ans;
    // ans = better(arr);
    ans = optimal(nums);
    cout<<endl<<"The length of longest consecutive: "<<ans;

    return 0;
}