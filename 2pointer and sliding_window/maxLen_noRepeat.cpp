//The question asks to return the length of the longest substring with no repeating characters.
//BRUTE FORCE METHOD
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int brute_findMaxSub(string s){
    //lets find every string, one i to iterate the loop and the second to find the sub-string and well also use hashing to track a characters occurence :
    int i=0,j=0;
    int maxLen = INT_MIN;
    while(i<s.length()){
        //well have to make a new set for every new substring
        map<char,int> mike;
        for(j=i;j<s.length();j++){ 
            if(mike.find(s[j])!=mike.end()){
                break;
            }
            mike[s[j]]++;
            maxLen = max(maxLen,j-i+1);
        }
        i++;
    }
    return maxLen;
} 

int optimal_findMaxSub(string s){
    int max_len = INT_MIN; // by the end of the outer loop, this will hold the max length
    map<char,int> mike; 
    for(int i =0;i<s.length();i++){
        int j =i;
        while(j<s.length()){
            if(mike.find(s[j])!=mike.end()){
                if(mike[s[j]]>=i){
                    max_len = max(max_len,j-i+1);
                    i = mike[s[j]]+1;
                }
            }
        }
    }
}

int main(){

    string s;
    cout<<endl<<"Enter the string : ";
    cin>>s;
    int ans =brute_findMaxSub(s); //The time complexity of this is O(n^2)
    int ans2 = optimal_findMaxSub(s);

    cout<<endl<<"The length of the maximum substring without any repeating characters through BRUTE FORCE : "<<ans;
    cout<<endl<<"The length of the maximym substring without any repeating characters through OPTIMAL TECHNIQUE : "<<ans2;

    return 0;
}