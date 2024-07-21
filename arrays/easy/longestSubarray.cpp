#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int posAndzero(vector<int> arr, int k){
    //this will use Two pointer
    int len=0,pSum=0;
    int j=0;
    for(int i=0;i<arr.size();i++){
        pSum+=arr[i];
        while(pSum>k)
        {
            pSum-=arr[j];
            j++;
        }
        if(pSum==k)
        {
            len=max(len,i-j+1);
        }
    }   
    cout<<endl<<"The time complexity of this is : O(2n)"<<endl<<"The space complexity of this is : O(1)"<<endl;
    return len;
}



int pnz(vector<int> arr, int k){
    //This will use hashmap
    map<int,int>mike;
    int pSum=0;
    int len=0;
    for(int i=0;i<arr.size();i++){
        pSum+=arr[i];
        int x_M_k=pSum-k;
        if(mike.find(x_M_k)!=mike.end()){
            len=max(len,i-mike[x_M_k]);
        }
        if(x_M_k==0){
            len=max(len,i+1);
        }
        //for zero case
        if(mike.find(pSum)==mike.end()){
            mike[pSum]=i;    
        }
    }
    cout<<endl<<"The time complexity is : O(nlogn) and space complexity is : O(n)"<<endl;
    return len;
}




int main()
{
    //This is to return the length of the longest subarray which whose sum is equal to a given integer
    vector<int> arr={1,2,3,1,1,1,1,3,3};
    int k=6;
    int i=0;
    cout<<"The vector is: ";
    while(i<arr.size()){
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;

    int ans=0;
//function call for if vector contains only +ve and 0s
    ans = posAndzero(arr,k);


//function call for if vector contains +ve, -ve and 0s
    // ans = pnz(arr,k);

    cout<<"The length of the longest Sub arrays is : "<< ans<<endl;
    return 0;
}