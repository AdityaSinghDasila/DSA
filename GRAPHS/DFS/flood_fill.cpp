#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> flood_fill(vector<vector<int>>& ans, int sr, int sc, int finalColor, vector<vector<int>>& visited){
    int iC = ans[sr][sc];
    int n = ans.size();
    int m = ans[0].size();
    ans[sr][sc]= finalColor;
    visited[sr][sc] = 1;
    int delR[] = {-1,0,1,0};
    int delC[] = {0,1,0,-1};
    for(int z = 0;z<4;z++){
        int r = sr + delR[z];
        int c = sc + delC[z];
        if(r>=0 && r<n && c>=0 && c<m && visited[r][c]!=1 && ans[r][c] == iC){
            flood_fill(ans,r,c,finalColor,visited);
        }
    }
    return ans;
}
int main(){
    //making a matrix
    vector<vector<int>> grid(3,vector<int>(3,0));
    grid[0][0]=1;
    grid[1][0]=1;
    grid[2][0]=1;
    grid[0][1]=1;
    grid[0][2]=1;
    grid[1][1]=1;
    grid[2][2]=1;

    cout<<endl<<"The matrix now is : "<<endl;
    for(auto i : grid){
        for(int j : i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    cout<<endl<<"Enter the epicenter node's coordinates : ";
    int i,j;
    cin>>i>>j;
    cout<<endl<<"Enter the final value you want to fill : ";
    int fC;
    cin>>fC;

    // we can do it with BFS as well as DFS
    //i chose DFS here
    //We need to send a visited matrix, because DFS works through recursion
    vector<vector<int>> visited(3,vector<int>(3,0));


    //fllod fill
    grid = flood_fill(grid,i,j,fC,visited);
    
    //The resulting matrix : 
    for(auto i : grid){
        for( int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}