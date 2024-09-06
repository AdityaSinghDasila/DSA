#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traverse(vector<int> adj[],int n,int x){
    vector<int> visited(n+1,0); // visited array initialised with 0;
    queue<int>q;
    q.push(x);
    visited[q.front()]=1;
    cout<<endl<<"BFS traversal : ";
    while(!q.empty()){
        int z = q.front();
        q.pop();
        cout<<z<<" ";
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    //first lets store a graph
    cout<<"Enter the no of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    cout<<endl<<"Enter the (m) edges : ";
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int x;
    cout<<endl<<"Enter the node you want to start BFS from : ";
    cin>>x;
    //BFS function call
    bfs_traverse(adj,m,x);

    return 0;
}