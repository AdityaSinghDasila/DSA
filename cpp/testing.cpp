#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void passVec(vector<int>v){
 cout<<"Vector address in function : "<<&v<<endl; 
}
int main()
{
  vector<int>v(5,1);
  cout<<"Vector address in main : "<<&v<<endl;
  passVec(v);
  return 0;
}