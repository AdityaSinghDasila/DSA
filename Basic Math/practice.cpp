#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkPal(int n){
    int x = n; 
    int rev =0;
    int k;
    while(x!=0){
        k=x%10;
        rev = rev*10 + k;
        x=x/10;
    }
    cout<<endl<<"rev: "<<rev;
    if(rev == n){
        return true;
    }else{
        return false;
    }
}

bool checkArm(int n){
    int sum =0;
    int dig =0;
    int x =n;
    while(x!=0){
        dig = x%10;
        sum += pow(dig,3);
        x=x/10;
    }
    if(sum==n){
        return true;
    }else{
        return false;
    }
}

void fibo(){
    int pp =0;
    int p=1;
    int count =2;
    int neww =0;
    cout<<pp<<" "<<p<<" ";
    while(count<=10){
        neww = pp+p;
        cout<<neww<<" ";
        pp = p;
        p = neww;
        count++;
    }
}

int main(){
    //check if pallindromr string or not
    int n;
    cout<<endl<<"Check if pallindrom or not : ";
    cin>>n;
    bool pall = checkPal(n);
    if(pall){
        cout<<endl<<"Yes pall";
    }else{
        cout<<endl<<"no";
    }

    //check armstrong number
    cout<<endl<<"Check armstrong : ";
    cin>>n;
    bool arms=checkArm(n);
    if(arms){
        cout<<endl<<"Yes armstrong";
    }else{
        cout<<endl<<"NO";
    }
    //fibonachi series
    cout<<endl<<"The fibonachi series : ";
    fibo();

    return 0;
}