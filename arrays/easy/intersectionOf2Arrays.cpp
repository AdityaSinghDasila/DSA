#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(int arr1[], int n, int arr2[], int m){
    vector<int> ans;
    int i=0,j=0;
    while(i<n && j<m){
    //if a common element is found
        if(arr1[i]==arr2[j]){
            cout<<endl<<"Hey equal !"<<endl;
            if(ans.size()==0 || ans.back()!=arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    //if no common element is found:-
        //if arr1 element is smaller
        else if(arr1[i]<arr2[j]){
            i++;
        }

        else{
            j++;
        }
    }
    return ans;
}

int main(){
    //The arrays are sorted already
    int arr1[]={1,2,3,4,5,6,6,7,7,9};
    int n=10;
    int arr2[]={2,3,3,5,14,14};
    int m=6;

    //between these two arrays, i want to find the intersection array
    vector<int> ans;

    cout<<"The two arrays are as follows :"<<endl;
    for(int i: arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i: arr2){
        cout<<i<<" ";
    }

    //calling the function
    ans = intersection(arr1,n,arr2,m);

    cout<<endl<<"The intersection vector : ";
    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}