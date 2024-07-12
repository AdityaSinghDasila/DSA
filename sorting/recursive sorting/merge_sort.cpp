#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& v, int low, int middle, int high){
    int left=low,right=middle+1; //two pointer that point to the beginnig of the two vectors (vector 1 is from low to middle, vector 2 is from middle+1 to high, both beign hypothetical), so left points to start of vec1 and right points to start of vec2
    
    //both of them vectors are sorted.(pichle recursive steps mai yaha ham aa chuke hai aur(assume kro lol) and from ground up single elements ab ham do sorted vectors ko ek bade vector mai daal ke vapas dee rahe hai)

    vector<int> temp; //a temporary vector

    while(left<=middle && right<=high)
    {
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    //koi ek array ka pointer pehle end pe pohoch gaya, doosri bachi vector ko seedhe copy kro as wo already sorted to hai hi
    //dono side ke liye loop daalo

    //for agar right vector bacha hai
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }

    while(left<=middle)//for left vector agar bacha hai
    {
        temp.push_back(v[left]);
        left++;
    }

    //ab is temp vector ko original v vector mai daalna hai, from index low to high
    for(int i=low;i<=high;i++)
    {
        v[i]=temp[i-low];
    }
    
};

void mergeSort(vector<int>& v, int low, int high){
    if(low==high)       //base case
        return;

    int middle = (low + high)/2;

    mergeSort(v,low,middle);//left side sorting recursively
    mergeSort(v,middle+1,high);//right side sorting recursively
    merge(v,low,middle,high);
};

int main(){

    vector<int>v={3,1,2,4,1,5,6,2,4};
    cout<<"Vector before sorting: ";
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    mergeSort(v,0,v.size()-1);

    cout<<"Vector after sort: ";
    for(int i: v){
        cout<<i<<" ";
    }


    return 0;
}