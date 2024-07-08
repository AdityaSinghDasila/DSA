#include <iostream>
using namespace std;

void constParams(const int& x){
    cout<<x<<endl;
    x=100;
}

int main(){
    int x=10;
    constParams(x);
    cout<<x;
    return 0;
}
// In this program, there will be a compile time error as there is an attempt to change the const variable. But const variables cannot be changed, they are read only.
//mike shaw also explained is_const, i donno what that is so check out his video
