//BFS traversal on an undirected graph
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traverse(vector<int> adj[],int x,int n){
    //we make a visited array,and mark nodes that have been pushed into the queue
    vector<int> visited(n+1,0);
    queue<int>q;
    q.push(x);//push the starting node into the queue and mark the starting node as visited in the vector
    visited[x]=1;
    cout<<endl<<"The BFS traversal of the Graph : ";
    while(!q.empty()){
        int z = q.front();
        q.pop();
        cout<<z<<" ";
        //now push the adjacent nodes of z, into the queue which have not been marked visited
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
};
int main(){
    //create and store graph in adjacency list
    cout<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    //creating the adjacency list to store neighbours of nodes
    vector<int> adj[n+1];
    cout<<endl<<"Enter the (m) edges : ";
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<endl<<"The adjacency list has been created : "<<endl;
    for(int i =1;i<n+1;i++){
        cout<<i<<" : "; 
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int x;
    cout<<endl<<"Enter the starting node : ";
    cin>>x;
    //call the bfs function
    bfs_traverse(adj,x,n);//send the adjacency list,its size or the no of nodes,the starting node as the arguments
    return 0;
}
*/