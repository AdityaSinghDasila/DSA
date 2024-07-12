#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<int>& v){
    for(int i=1;i<v.size();i++){
        for(int j=i;j>0;j--){
            if(v[j]<v[j-1])
            {
                swap(v[j],v[j-1]);
            }
            else{
                break;
            }
        }
    }
}
int main(){
    vector<int> v= {45,12,4,1,6,0,23,23,1,89,11};

    cout<<"The vector: ";
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    insertion(v);

    cout<<"The vector after sorting is : ";
    for(int i: v){
        cout<<i<<" ";
    }
    return 0;
}