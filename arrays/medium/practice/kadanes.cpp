/*
    find the maximum sum sub array in the given array.
    also print that array
*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSumSubarray(vector<int> arr){
    vector<int>ans;
    
    int MAX_SUM = INT_MIN;
    int sum=0;
    int start=0,fend=0,fstart=0;
    for(int i=0;i<arr.size();i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>MAX_SUM)
        {
            MAX_SUM=sum;
            fend=i;
            fstart=start;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    ans.push_back(MAX_SUM);
    ans.push_back(fstart);
    ans.push_back(fend);
    return ans;
}


int main(){
    vector<int> arr= {-2,1,-3,4,-1,2,1,-5,4};
    
    cout<<"The array : ";
    for(int i: arr){
        cout<<i<<" ";
    }

    vector<int>ans;
    ans=maxSumSubarray(arr);

    cout<<endl<<"The largest sum of : "<<ans[0]<<"  from the sub array : ";
    for(int i=ans[1];i<=ans[2];i++){
        cout << arr[i]<<" ";
    }

    return 0;
}