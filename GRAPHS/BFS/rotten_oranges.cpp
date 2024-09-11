#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rotten(vector<vector<int>> grid){
    //we apply bfs in an array
    //first find the rooten rotten oranges and push them into a queue. why? MULTIPLE STARTING POINTS
    queue<pair<pair<int,int>,int>> q; //The first two ints are for i,j coordinates and the third int is for the time at which rotting action happens
    
    //also make a visited replicate matrix, so that if rotten orange has already rotten an orange at time t, then marking that orange as rotten prevents it from rotting again by another orange later down the line
    vector<vector<int>> visited(3,vector<int>(3,0));   
    
    int size = grid.size();

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else{
                visited[i][j]=0;
            }
        }
    }

    //The rotting oranges are already in queue, the visited matix is ready,now lets start the BFS.
    int delR[] = {-1,0,+1,0};
    int delC[] = {0,1,0,-1};
    int ans =0;
    while(!q.empty()){
        pair<pair<int,int>,int> N = q.front();
        int i = N.first.first;
        int j = N.first.second;
        int t = N.second;
        q.pop();
        //now you have a rotten orange coordinate that is stored at N. now rot,visit,and push the adjacent oranges
        for(int z =0;z<4;z++){
            int r = i+delR[z];
            int c = j+delC[z];
            if(r>=0 && r<size && c>=0 && c<size && visited[r][c]!=1 && grid[r][c]==1){
                grid[r][c]=2;
                visited[r][c]=1;
                q.push({{r,c},t+1});
                ans = t+1;
            }
        }
    }
    for(auto i : grid){
        for( int j : i){
            if(j==1){
                return -1;
            }
        }
    }
    return ans;
}
int main(){
    //making a 2d matrix of 5x5 dimensions
    vector<vector<int>> grid(3,vector<int>(3,0));
    //now lets fill in the oranges : 
    grid[0][1]=1;
    grid[0][2]=1;
    grid[1][0]=1;
    grid[1][1]=1;
    grid[2][1]=1;
    grid[2][2]=1;
    //now lets fill the rotten orange
    grid[0][0]=2;
    cout<<endl<<"The box at t = 0 time looks like this : "<<endl;
    for(auto i : grid){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    //Q.find the minimum time in which all oranges become rotten
    int ans = rotten(grid);

    if(ans==-1)
    {
        cout<<endl<<"It is not possible to rot all the oranges : ";
    }else{
        cout<<"The minimum amount of time required to rot all oranges : "<<ans;
    }

    return 0;
}