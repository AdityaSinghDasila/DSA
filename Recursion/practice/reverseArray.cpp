#include <iostream>
#include <vector>
using namespace std;
void reverseArr(vector<int>& v,int l, int r){
    if(l>=r){
        return;
    }
    swap(v[l],v[r]);
    reverseArr(v,l+1,r-1);
}
int main(){
    vector<int> v;
    for(int i=0;i<5;i++){
        v.push_back(i);
    }
    reverseArr(v,0,v[v.size()-1]);
    for(int i=0;i<5;i++){
        cout<<v[i]<<endl;
    }
    return 0;
}