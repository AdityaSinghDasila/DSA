#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {7,7,7,7,8,9,10,22,34,56,1,2,3,4,5,6,7};
    cout<<endl<<"The array : ";
    for(int i:  arr){
        cout<<i<<" ";
    }

    int first =0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first + (last - first)/2;
    while(first <= last){
        middle = first + (last -first)/2;
        
    }
    return 0;   
}