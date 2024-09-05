#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<endl<<"Enter the number of nodes and no of edges in the graph : ";
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j =0;j<n+1;j++){
            adj[i][j] = 0;
        }
    }
    cout<<"Now enter the (m) edges : ";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        cout<<"taken "<<endl;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    cout<<endl<<"The adjacency matrix now : "<<endl;
    for(int i=0;i<n+1;i++){
        for(int j =0;j<n+1;j++){
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}