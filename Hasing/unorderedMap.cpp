#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    vector<int>data = {0,1,2,3,3,3,4,5,0,0,5,9,9};
    
    //creating unordered map
    unordered_map<int,int>umap;

    //filling map
    for(int i=0;i<data.size();i++){
        umap[data[i]]++;
    }//now the unordered map has been filled

    //now traversing the map using range based loop
    for(auto ans : umap){
        cout<<"The frequency of "<<ans.first<<" is : "<<ans.second<<endl;
    }

    return 0;
}

/*
    in map datatype in map<datatype,datatype>mapname can be anything, int,float,vector,pair etc.

    in unorder map:-
            "the datatype of key and value must be of INDIVIDUAL DATATYEP like int,double,float,char etc"
            "it cannot be pair,vector etc non-individual datatype"
*/


/*
    The order of elements "CANNOT BE PREDETERMINED IN UNORDERED MAP"

    unordered_map is used because its time complexity is O(1),
    only in case of collision which is very very rare, its TC become O(n).

    Thus always use unordered map unless TLE or you want keys sorted, or you want key/value to be pair or vector etc.
*/


/*
    OUTPUT OF ABOVE CODE:-
        The frequency of 9 is : 2
        The frequency of 5 is : 2
        The frequency of 1 is : 1
        The frequency of 0 is : 3
        The frequency of 2 is : 1
        The frequency of 3 is : 3
        The frequency of 4 is : 1

        notice that there is no exact order in which unordered map stores data.
*/