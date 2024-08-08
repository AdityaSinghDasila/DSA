/*  RETURN THE INDEX OF THE ELEMENT FROM AN ARRAY THAT IS ROTATED K TIMES AFTER SORTING   */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={10,10,10,10,10,10,10,10,10,10,10,10,11,12,13,14,15,16,17,18,19,20,21,1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    for(int i : arr){
        cout<<i<<" ";
    }
    
    cout<<endl<<"Enter the element you want the to return the index of : ";
    int el;
    cin>>el;

    int first =0;
    int last = arr.size()-1;
    int ans = arr.size();
    int middle = first + (last-first)/2;
    while(first<=last){
        middle = first +(last -first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        else if(arr[first]== arr[middle] && arr[last]==arr[middle]){
            first = first +1;
            last = last -1;
        }
        else if(arr[first]<=arr[middle]){
            //left is sorted
            if(el>=arr[first] && el<arr[middle]){
                last = middle -1;
            }
            else{
                first = middle+1;
            }
        }
        else{
            //right is sorted
            if(el>arr[middle] && el<=arr[last]){
                first = middle +1;
            }
            else{
                last = middle-1;
            }
        }
    }

    if(ans!=arr.size()){
        cout<<endl<<"The index of element in the array is : "<<ans;
    }    
    else{
        cout<<endl<<"The element was not found!! ";
    }

    return 0;
}
*/



/*  RETURN THE FIRST AND LAST OCCURENCE OF AN ELEMENT IN A SORTED ARRAY */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,2,3,4,5,6,7,8,9,9,9,10,11,12,13};
    cout<<endl<<"The array : ";
    for(int i:  arr){
        cout<<i<<" ";
    }

    int el;
    cout<<endl<<"Enter the element you want the index of : ";
    cin>>el;

    int first = 0;
    int last = arr.size()-1;
    int middle = first + (last - first)/2;
    int ub = arr.size();
    int lb = arr.size();

    //find the ub and lb seperately
    while(first <= last){
        middle = first +  (last -first)/2;
        if(arr[middle]>el){
            ub = middle;
            last = middle-1;
        }
        else if(arr[middle]<=el){
            first = middle +1;
        }
    }
    
    //now the lb
    first =0;
    last = arr.size()-1;
    while(first<=last){
        middle = first + (last - first)/2;
        if(arr[middle]<el){
            first = middle+1;
        }
        else if(arr[middle]>=el){
            lb = middle;
            last = middle -1;
        }
    }

    if(lb!=arr.size() && lb!=ub){
        cout<<endl<<"The starting index : "<<lb<<endl<<"The ending index : "<<ub-1;
    }else{
        cout<<endl<<"The element was not found ! ";
    }

    return 0;
}
*/

/*  SEARCH AN ELEMNT IN A ROTATED SORTED ARRAY WITH DUPLICATES */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int> arr = {11,12,13,14,15,16,17,1,2,3,4,5,6,7,8,9,10};
    cout<<endl<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    cout<<endl<<"Enter the element you want to search : ";
    int el;
    cin>>el;

    int first = 0;
    int last = arr.size()-1;
    int middle = first + (last - first)/2;
    int ans = arr.size();

    while(first <= last){
        middle = first + (last -first)/2;
        if(arr[middle]==el){
            ans = middle;
            break;
        }
        else if(arr[middle]==arr[first] && arr[middle]==arr[last]){
            first = first +1;
            last -=1;
        }
        else if(arr[first]<=arr[middle]){
            //left side is sorted
            if(el>=arr[first] && el<=arr[middle]){
                last = middle -1;
            }
            else{
                first = middle+1;
            }
        }
        else if(arr[middle]<=arr[last]){
            //right is sorted
            if(el<=arr[last] && el>=arr[middle]){
                first = middle +1;
            }
            else{
                last = middle -1;
            }
        }
    }
    if( ans != arr.size() ){
        cout<<endl<<"The index : "<<ans;
    }else{
        cout<<endl<<"NOT FOUND!! ";
    }
    
    return 0;
}
*/

/*  FIND MINIMUM IN A ROTATED SORTED ARRAY */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr= {8,9,10,23,2,3,4,5,7};
    cout<<endl<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    int first =0;
    int last = arr.size()-1;
    int middle = first + (last - first)/2;
    int mini = INT_MAX;
    while(first <= last){
        middle = first+(last -first)/2;
        if(arr[middle]>=arr[first]){
            mini = min(mini,arr[first]);
            first = middle +1;
        }
        else{
            mini = min(mini,arr[middle]);
            last = middle-1;
        }
    }

    cout<<endl<<"The minimum of the array is : "<<mini;

    return 0;
}
*/

/*  FIND THE SINGLE ELEMENT IN A SORTED ARRAY */
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};
    cout<<endl<<"The array : ";
    for(int i : arr){
        cout<<i<<" ";
    }

    int first = 1;
    int last = arr.size()-2;
    int middle = first + (last-first)/2;
    int ans = arr.size();

    while(first<=last){
        middle = first + (last -first)/2;
        if(arr[0]!=arr[1]){
            ans = 0;
            break;
        }
        if(arr[arr.size()-1]!=arr[arr.size()-2]){
            ans = arr.size()-1;
            break;
        }
        if(arr[middle]!=arr[middle-1] && arr[middle]!=arr[middle+1]){
            ans = middle;
            break;
        }
        else if(middle % 2 == 0){
            if(arr[middle]==arr[middle-1]){
                last = middle -1;
            }
            else{
                first = middle +1;
            }
        }
        else{
            if(arr[middle]==arr[middle-1]){
                first = middle +1;
            }
            else{
                last = middle -1;
            }
        }
    }

    cout<<endl<<"The element that is not in pair is : "<<arr[ans];

    return 0;
}
*/