#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    //lets see given vector (not using array lmao)
    vector<int>data ={1,2,3,4,5,1,2,3,8,8,8,8,8,9,0,3};
    
    map<int,int>freq;
    for(int i=0;i<data.size();i++){ 
        freq[data[i]]++;
    }//now the map has been filled with data and their frequencies and the order is ascending wrt to keys

    //to traverse the map
    for(auto PAIR : freq){
        cout<<"frequency of "<<PAIR.first<<" is:"<<PAIR.second<<endl;
    }//range based loop is used here

    return 0;
}
/*
    frequency of 0 is:1
    frequency of 1 is:2
    frequency of 2 is:2
    frequency of 3 is:3
    frequency of 4 is:1
    frequency of 5 is:1
    frequency of 8 is:5
    frequency of 9 is:1

    notice how the keys are in acending order, that is map for you.
    so while accesing map, the first key,value pair you find is the pair with smallest key, which is 0 here.

    Time complexity of MAP: sorting - O(    log(n)  )    
                            fetching- O(    log(n)  )   
                            which is more than TC of unordered map. THUS use unordered map unless TLE hits or sorted values matter.
*/


/*
    range based loop is used in map traversal:

    for(x : DS name)
    {
        cout<<x<<endl;
    }
    here, x is an element of the DS. 
    over each iteration, x is changed, which will be new element of DS until the whole DS is traversed.

    so in map ranged based loop:

    for(auto datapair : mapname)
            the datapair is the pair that is key and value.
            freq is the map name (i should have named it better tbh, this is confusing)
            to access key, datapair.first no bracket
            to access value, datapair.second no bracket
*/
