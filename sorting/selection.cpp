#include <iostream>
#include <vector>
using namespace std;

void selection(vector<int>& v){     //pass by reference: thus changes will be reflected
    int i=0;
    for(i=0;i<v.size();i++)
    {
        int min=i;
        for(int j=i;j<v.size();j++)
        {
            if(v[j]<v[min])
            {
                swap(v[j],v[min]);
            }
        }
    }
}
int main(){
    vector<int>v={1,3,4,5,2,8,14,12};
    cout<<"The vector before sorting is: ";
    for(int i : v){
        cout<<i<<" ";
    }

    selection(v);

    cout<<endl<<"After selection sort, the new array is: ";
    for(int i : v){
        cout<<i<<" ";
    }

    return 0;
}