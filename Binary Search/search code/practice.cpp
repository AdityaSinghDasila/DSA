/* binary search code */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The array : ";
    for(int i:arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element you want to search :";
    cin>>el;

    int ans = arr.size();
    int first = 0;
    int last = arr.size()-1;
    int middle = first+ (last-first)/2;
    while(first<=last){
        middle = first +(last-first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        else if(arr[middle]>el){
            last = middle -1;
        }
        else if(arr[middle]<el){
            first =middle +1;
        }
    }

    if(ans!=arr.size()){
        cout<<endl<<"The element is present at index :"<<ans;
    }else{
        cout<<endl<<"The element was not found!!";
    }
    
    return 0;
}
*/

/*  BINARY SEARCH CODE */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The array : ";
    for(int i: arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element you want to search : "; 
    cin>>el;

    int first = 0;
    int last = arr.size()-1;
    int ans = -1;
    int middle = first +(last-first)/2;
    while(first<=last){
        middle = first+(last-first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        if(arr[middle]<el){
            first=middle+1;
        }
        else if(arr[middle]>el){
            last = middle-1;
        }
    }
    if(ans!=-1){
        cout<<endl<<"The element was found at index :"<<ans;
    }else{
        cout<<endl<<"The element was not found in the array!!";
    }

    return 0;
}
*/

/* lower bound */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The array :";
    for(int i: arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element you want to find the upper bound for : ";
    cin>>el;

    int first =0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first+(last-first)/2;
    while(first <= last){
        middle = first+(last-first)/2;
        if(arr[middle]>=el){
            ans = middle;
            last = middle-1;
        }
        else if(arr[middle]>el){
            first = middle+1;
        }
    }
    cout<<endl<<"The upper bound will be at the index : "<<ans; 
    return 0;
}
*/


/*The upper bound*/
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The arrays : ";
    for(int i: arr){
        cout<<i<<" ";
    } 

    int el;
    cout<<endl<<"Enter the element you want the upper bound for : ";
    cin>>el;

    int first = 0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first +(last-first)/2;
    while(first<=last){
        middle = first+(last-first)/2;
        if(arr[middle]>el){
            ans = middle;
            last = middle-1;
        }
        else if(arr[middle]<=el){
            first = middle+1;
        }
    }
    cout<<endl<<"The upper bound will be found at the index : "<<ans;
    return 0;
}
*/

/* floor of the an element in the array */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The array : ";
    for(int i: arr ){
        cout<<i<<" ";
    } 

    cout<<endl<<"Enter the element for which you want the floor of : ";
    int el;
    cin>>el;

    int first =0;
    int last = arr.size();
    int floor = -1;
    int middle = first+ (last-first)/2;
    while(first <= last){
        middle = first+(last-first)/2;
        if(arr[middle]<=el){
            floor = middle;
            first = middle+1;
        }
        else if(arr[middle]>el){
            last= middle-1;
        }
    }
    if(floor!=-1)
    cout<<endl<<"The floor of "<<el<<" in the array is : "<<arr[floor]<<", at the index : "<<floor;

    else
        cout<<endl<<"floor not found";
    return 0;
}
*/

/* Ceil of an element in an array */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr ={1,2,3,4,5,6,7,8,9,10,200};
    cout<<endl<<"The array : ";
    for(int i: arr){
        cout<<i<<" ";
    } 


    int el;
    cout<<endl<<"Enter the element for which you want the ceil for : "; 
    cin>>el;

    int ceil = arr.size();
    int first = 0;
    int last = arr.size()-1;
    int middle = first +(last - first)/2;

    while(first<=last){
        middle = first+(last-first)/2;
        if(arr[middle]>=el){
            ceil = middle;
            last = middle-1;
        }
        else if( arr[ middle]<el){
            first = middle+1;
        }
    }


    if(ceil!= arr.size()){
        cout<<endl<<"The ceil of "<<el<<" in the array is : "<<arr[ceil]<<" at the index: "<<ceil;
    }else{
        cout<<endl<<"Ceil not found";
    }

    return 0;
}