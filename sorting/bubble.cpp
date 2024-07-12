#include <iostream>
#include <vector>
using namespace std;
void bubble(vector<int>& v){
    int i=0,j=0;
    for(i=0;i<v.size();i++){
        for(j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
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