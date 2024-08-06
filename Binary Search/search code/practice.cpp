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
