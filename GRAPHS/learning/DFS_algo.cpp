#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs_traverse(vector<int> adj[],int n,int x,vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(auto i : adj[x]){
        if(!visited[i]){
            dfs_traverse(adj,n,i,visited);
        }
    }
}
int main(){
    //creating graph first and storing in adjacency list
    cout<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    
    cout<<endl<<"Enter the (m) edges : ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been filled

    cout<<endl<<"The adjacency list of graph : ";
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int x;
    cout<<endl<<"Enter the starting node : ";
    cin>>x;
    //since dfs will be recursive function, im sending a visited array from here only through refernce
    vector<int> visited(n+1,0);
    //calling the dfs function
    cout<<endl<<"The DFS traversal of the graph is : ";
    dfs_traverse(adj,n,x,visited);
    
    return 0;
}