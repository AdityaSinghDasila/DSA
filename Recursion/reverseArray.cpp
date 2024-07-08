// Problem Statement: You are given an array. The task is to reverse the array and print it. 

// Examples:

// Example 1:
// Input: N = 5, arr[] = {5,4,3,2,1}
// Output: {1,2,3,4,5}
// Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> revArr(vector<int> arr,int l, int r){
    /*
    vector<int>reverse;
    int i=arr.size()-1;
    while(i>=0)
    {
        reverse.push_back(arr[i]);
        i--;
    }
    return reverse;
    */

   //now through recursion
   cout<<"this runs";
    if(l>=r){
        cout<<"this is last: "<<endl<<arr[0];
        return arr;
        }
    swap(arr[l],arr[r]);
    return revArr(arr,l+1,r-1);
};

int main()
{
    vector<int>arr;
    cout<<"Enter the size of the vector: ";
    int N,x,i;
    cin>>N;
    i=0;
    while(i<N)
    {
        cin>>x;
        arr.push_back(x);
        i++;
    };
    i=0;
    cout<<"The vector has been made: ";
    while(i<arr.size()){
        cout<<arr[i];
        i++;
    }

    //reverse array 
    vector<int>reA;
    reA=revArr(arr,0,arr.size()-1);
    i=0;
    // cout<<"size of reA vector: "<<reA.size();
    cout<<"The reverse vector has been made: ";
    while(i<reA.size()){
        cout<<reA[i];
        i++;
    }
    return 0;
}