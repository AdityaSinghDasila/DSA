#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={5,6,7,1,3,2,4};
    cout<<endl<<"Was this vector sorted and rotated ? : ";
    for(int i: arr){
        cout<<i<<" ";
    }
    //we first see in the vector if there is more than one point of irregularity. and then we check the first and last elements as if they were connected or not
    int fluctuation =0;
    int n = arr.size();
    int prev = INT_MAX;
    for(int i =0;i<n;i++){
        if(arr[i]<prev){
            fluctuation++;
            prev = arr[i];
        }else{
            prev = arr[i];
        }
    }
    if(arr[0]<arr[n-1]){
        fluctuation++;
    }
    if(fluctuation>1){
        cout<<endl<<"The array was never sorted";
    }else{
        cout<<endl<<"The array was sorted and rotated";
    }
    return 0;
}