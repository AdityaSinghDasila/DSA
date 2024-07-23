#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSumSubArray(vector<int>& arr){
    int MAX_SUM = INT_MIN;
    int sum=0;
    int l=0,left=0,right=0;
    for(int i = 0;i<arr.size();i++){
        if(sum==0){
            l=i;
        }
        sum+=arr[i];
        if(sum>MAX_SUM){
            MAX_SUM=sum;
            right=i;
            left=l;
        }
        if(sum<0)
            sum=0;
    }
    cout<<MAX_SUM<<endl;
    vector<int> ans;
    ans.push_back(MAX_SUM);
    ans.push_back(left);
    ans.push_back(right);
    
    return ans;
}
int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"The vector :";
    for(int i: arr){
        cout<<i<<" ";
    }

    vector<int> ans = maxSumSubArray(arr);

    cout<<endl<<"The maximum sum is "<<ans[0]<<" from the subarray :- "<<endl;
    for(int i=ans[1];i<=ans[2];i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


//please mug this algo up.(Even if you get the intuition)