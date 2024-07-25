/*

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void selection(vector<int>& arr){
    //minimum ko uthake sabse front phekna
    int min=0;
    for(int i=0;i<arr.size();i++){
        min=i;
        for(int j=i;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){
    vector<int>arr ={23,12,2,4,1,54,3,67,97,1452,0,12,2,7,7,9};
    cout<<"The vector before sorting :";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
    selection(arr);

    cout<<endl<<"The vector after selection sort : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selection(vector<int>& arr){
    //in selection, we grab the minimum element and throw it first
    for(int i=0;i<arr.size();i++){
        int min=i;
        for(int j=i;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        } 
        swap(arr[i],arr[min]);
    }
}

int main(){
    vector<int> arr ={23,12,2,4,1,54,3,67,97,1452,0,12,2,7,7,9};
    cout<<"The vector before sorting : ";
    for(int i:  arr ){
        cout<<i<<" ";
    }

    selection(arr);
    
    cout<<endl<<"The vector after sorting :";
    for(int i: arr){
        cout<<i<<" ";
    }

    return 0;
}