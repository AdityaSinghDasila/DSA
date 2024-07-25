/*   VERY IMPORTANT, PLEASE PRACTICE
    given a matrix, if an element is 0, then set its entire row and column to 0
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void zeroTurn(vector<vector<int>>& matrix){
    int rvar=matrix[0][0]; //to mark if any j=0 column element is 0 or not
    
    
    //normal traversal of matrix to check which element is zero and updating both the DS
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(j==0 && matrix[i][j]==0){
                rvar=0;
            }
            else if(j!=0 && matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    } //now the DS have been marked for future checking of whether a row need zerofication or not


    for(int i=matrix.size()-1;i>0;i--){
        for(int j=matrix[0].size()-1;j>0;j--){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }//now the rows and columns that are not part of 2 DS are filled with 0 where required


    //now we fill the 1st DS (0th row DS by looking at themself and matrix[0][0])
    int j=matrix[0].size()-1;
    while(j>0){
        if(matrix[0][0]==0){
            matrix[0][j]=0;
        }
        j-=1;
    }

    int i=matrix.size()-1;
    while(i>=0){
        if(rvar==0){
            matrix[i][0]=0;
        }
        i-=1;
    }
}   

int main(){
    vector<vector<int>> matrix ={{1,1,1},{1,0,1},{1,1,1}};
    cout<<"The matrix before operation : "<<endl;
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    zeroTurn(matrix);

    cout<<"The matrix AFTER operation : "<<endl;
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}