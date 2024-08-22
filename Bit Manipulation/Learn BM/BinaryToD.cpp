#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binaryToD(string n){
    int ans=0;
    for(int i=n.length()-1;i>=0;i--){
        if(n[i]=='1')
            ans = ans + pow(2,n.length()-1-i);
            cout<<endl<<" for "<<n[i]<<" : "<<ans<<endl;
    }
    return ans;
}
int main(){
    cout<<endl<<"Enter binary number : ";
    string n;
    cin>>n;
    int ans = binaryToD(n);
    cout<<endl<<"The conversion of "<<n<<" to decimal is : "<<ans;
    return 0;
}