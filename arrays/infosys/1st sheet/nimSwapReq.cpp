#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bobSwaps(vector <int> arr){
    int swaps=0;
    if(arr.size()==2 || arr.size()==0){
        return 0;
    }
    vector<int>sorted;
    sorted = arr;
    sort(sorted.begin(),sorted.end()); //the array has been sorted

    vector<int>target;
    int i=0,j=sorted.size()-1;
    while(i<j){
        target.push_back(sorted[i]);
        target.push_back(sorted[j]);
        i++,j--;
    }//target array is filled
    
    unordered_map<int,int>arrIn;
    for(int i=0;i<arr.size();i++){
        arrIn[arr[i]]=i;
    }//now we have the index of each element of the original arr array

    //now fill a new hashmap with key->value where key: number encountered, value: what no it need to be with.
    unordered_map<int,int>needEl;
    for(int i=0;i<target.size()-1;i=i+2){
        needEl[target[i]]=target[i+1];
        needEl[target[i+1]]=target[i];
    }

    //now lets traverse the original array, swapping directly with the needed element
    for(int i=0;i<arr.size()-1;i=i+2){
        if(arr[i+1]!=needEl[arr[i]]){
            // int element = needEl[arr[i]];
            swap(arr[i+1],arr[arrIn[needEl[arr[i]]]]);
            swaps++;
        }
    }
    cout<<"min swaps : "<<swaps;
    cout<<endl;
    return swaps;
}



int main(){

    vector<int> arr = {4,1,2,9,3,6};

    cout<<"The array initially : ";
    for(int i : arr ){
        cout<<i<<" ";
    }

    int minSwaps = bobSwaps(arr);
    
    cout<<endl<<"The minimum swaps required will be : "<<minSwaps<<endl;

    return 0;
}