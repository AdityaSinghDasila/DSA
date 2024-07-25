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

/*

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
*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int first,int middle, int last){
    //now we have two hypotheically virtual arrays, which are sorted.
    // one is from first-->middle, the second is from middle+1-->last
    //we make two pointers left and right and put them on the starting of the two arrays respectively.
    //since the two arrays are sorted already, we compare the two arrays and then put the smaller element into a temporary vector. When the vector is filled, this merged array is the new bigger sorted array.
     
    int left=first, right= middle+1;
    vector<int> temp;
    while(left<=middle && right<=last){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //emptying the array that did not get exhausted in the above array
    while(left<=middle)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=last){
        temp.push_back(arr[right]);
        right++;
    }

    //now the temp array has been filled.

    //transferring the whole temp array[0->size()-1]   into the original array [FIRST-->LAST]
    for(int i=first;i<=last;i++){
        arr[i]=temp[i-first];
    }

    //merge has been done
}
void mergeSort(vector<int>& arr,int first, int last){
    //now lets break them down by recursion
    if(first==last)
        return;
    int middle = (first+last)/2;
    mergeSort(arr,first,middle);
    mergeSort(arr,middle+1,last);
    merge(arr,first,middle,last);
}

using namespace std;
int main(){
    vector<int> arr ={34,12,4,2,12,53,23,45,2,36,78,6,4,82,0,0,5,4,3};
    cout<<"The vector before sorting :";
    for(int i : arr){
        cout<<i<<" ";
    }

    mergeSort(arr,0,arr.size()-1); //sent the first and last element index

    cout<<endl<<"The vector after sorting :";
    for(int i: arr){
        cout<<i<<" ";
    }

    return 0;
}