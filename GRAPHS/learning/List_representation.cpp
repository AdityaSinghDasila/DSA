#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    //for undirected graph
    cout<<endl<<"Enter the nodes and edges : ";
    int n,m;
    cin>>n>>m;
    
    //creating adjacency list
    vector<int> adj[n+1];
    cout<<endl<<"Enter the (m) edges : ";
    
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//This line will not be used in a directed graph because of unidirectionality
        cout<<"done"<<endl;
    }
    
    for(int i =0;i<n+1;i++){
        cout<<endl<<i<<" : ";
        for(int j =0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}