#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void passVec(vector<int> v){ //if i want t0 pass the vector in a pass by reference way : void passVec(vector<int>& v){}
    cout<<"Size of the passed vector: "<<v.size()<<endl;
}
int main(){
    //since it is not possible to pass by value for an array and also we MUST pass size also in the parameter, a solution to this is the use of vector, as its size can be calculated dynamially.
    vector<int> v(10,2);
    passVec(v);
    return 0;
}