#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string DecToBinary(int dec){
    string ans="";
    while(dec!=0){
        if(dec%2==1){
            ans+='1';
        }else{
            ans+='0';
        }
        dec/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    cout<<endl<<"Enter the number in decimal : ";
    int n;
    cin>>n;
    string ans = DecToBinary(n);
    cout<<endl<<"The binary conversion of "<<n<<" is : "<<ans;
    return 0;
}