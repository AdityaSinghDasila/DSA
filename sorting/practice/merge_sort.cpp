/*
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int low, int middle, int high){
    //we now have two virtual arrays: low-middle    middle+1-high
    int left= low;
    int right=middle+1;
    vector<int> temp;
    while(left<=middle && right<=high)
    {
        if(v[left]<=v[right])
        {   
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left<=middle)
    {
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }

    //now to transfer to the v vector
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }
}

void mergeSort(vector<int>& v, int low, int high){
    if(low==high)
        return;

    int middle= (low+high)/2;

    mergeSort(v,low,middle);
    mergeSort(v,middle+1,high);

    merge(v,low,middle,high);
}


int main(){

    vector<int>v ={56,1,4,6,1,5,7,97,34,24,46,85,23,15,17,19,16,23};

    cout<<"The vector is :";
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    mergeSort(v,0,v.size()-1);

    cout<<"The vector after sorting: ";
    for(int i: v){
        cout<<i<<" ";
    }

    return 0;
}
*/


