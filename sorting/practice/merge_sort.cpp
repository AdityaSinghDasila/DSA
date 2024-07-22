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


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int l, int middle, int r){
    //now i have two virtual arrays, WHICH ARE SORTED
    //thus i need two pointers and slide them while filling the temp vector
    vector<int>temp;
    int i=l;
    int j=middle+1;
    while(i<=middle && j<=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }//one of i or j array has exhausted, so now we need to simply fill the array directly which has not been exhausted as it is sorted already

    while(i<=middle){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }
    //now we need to fill the arr vector[l,r] with the temp vector[0,temp.size()]
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
}

void mergeSort(vector<int>& arr,int l, int r){
    if(l==r)
        return;
    int middle=(l+r)/2;
    mergeSort(arr,l,middle);
    mergeSort(arr,middle+1,r);
    merge(arr,l,middle,r);
}

int main(){
    vector<int>arr = {34,12,4,2,12,53,23,45,2,36,78,6,4,82,0,0,5,4,3};

    cout<<"The vector before sorting : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    mergeSort(arr,0,arr.size()-1);

    cout<<endl<<"The vector after sorting : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";   
    }

    return 0;
}