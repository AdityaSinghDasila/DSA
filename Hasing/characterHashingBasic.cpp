#include <iostream>
using namespace std;
int main(){
    int hsh[26]={0},index;
    cout<<"enter the number of elements to enter: ";
    int n,i=1;
    char ele;
    cin>>n;
    while(i<=n){
        cin>>ele;
        index = ele - 'a';
        hsh[index]++;
        i++;
    }
    cout<<"enter the character you want to search :";
    cin>>ele;
    cout<<hsh[ele-'a']<<" is the frequency of "<<ele;

    return 0;
}
//whenever you want to hash characters only, then its a no brainer to use array hasing as the maximum possible characters are only 256 (0 to 255), thus the hash array can only be a maximum int hsh[256].