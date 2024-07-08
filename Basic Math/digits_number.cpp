#include <bits/stdc++.h>
using namespace std;
int main()
// {
//     //if we want to count digits in a number
//     int x=566,count=0;
//     while(x>0)
//     {
//         count++;
//         x=x/10;
//     }
//     cout<<count;
//     return 0;
// }//tc=O(n)


{
    int x=5666,count=0,y=0;
    y=(int)log10(x)+1;
    cout<<y; //gives the number of digits in a tc: log(n)
    return 0;
}