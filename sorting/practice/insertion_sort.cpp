/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else    
                break;
        }
    }
}
int main(){
    vector<int> arr= {34,12,34,1,2,5,1,2,5,646,7,6,434,7,8,9,22,34,54,32};
    
    cout<<"The vector before sorting : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    insertion(arr);

    cout<<endl<<"The vector after sorting: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertion(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            else
                break;
        }
    }
}

int main(){
    vector<int> arr= {323,23,1,23,51,2,31,34,2,1,23523,53,2123,1,1,21,1,0};
    cout<<"The vector before sorting : ";
    for(int i:arr){
        cout<<i<<" ";
    }

    insertion(arr);

    cout<<endl<<"The vector after sorting :";
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;   
}