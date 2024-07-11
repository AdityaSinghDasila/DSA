#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;//enter the no of data to enter
    vector<int>hash(50,0);//assuming the user does not enter numbers greater than 49.
    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
        hash[element]++;
    }

    int search;
    cout<<"Enter the element to search: ";
    cin>>search;
    cout<<hash[search]<<" is the frequency of "<<search;
    
    return 0;
}