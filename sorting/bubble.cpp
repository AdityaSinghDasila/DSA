#include <iostream>
#include <vector>
using namespace std;
void bubble(vector<int>& v){
    int i=0,j=0;
    for(i=0;i<v.size();i++){
        int didswap=0;
        for(j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                didswap=1;
            }
        }
        if(didswap==0)
            break;
    }
}
int main(){
    vector<int> v={1,4,2,3,6,8,23,12,55,9};
    cout<<"The vector is : ";
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
    
    bubble(v);

    cout<<"Now the bubble sorted vector: ";
    for(int i: v){
        cout<<i<<" ";
    }

    return 0;
}

/*
    DIDSWAP optimization:
    if in any iteration, there is no swap in the j loop, this mean that the whole array is already im ascending order. thus no further iterations needed.
    thus, if didswap is not turned ==1 by jloop, then no swap was done => array sorted => break form i loop.
*/